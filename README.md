# Description

This repository is an example of how a [codespace](https://github.com/features/codespaces) can be
set up for the development of a C/C++ application.

Setting up a development environment for C/C++ applications is a notoriously difficult task. Working on a
complex project may involve installing dozens of system packages, fetching and building external
libraries using different build systems, and defining various environment variables so the
desired output binaries can be generated. In certain cases, doing all that work may take days, if
not weeks, producing a great deal of frustration among developers, especially those joining a new
team or organization.

A well-designed codespace addresses this problem head-on: it is the combination of (1) a Docker
container with all the necessary system packages, libraries etc. already pre-installed and (2) an
editor configured with the optimal settings and plugins which allow a developer to start
 working on the project's code immediatelly. No manual setup needed. No wrestling with the
development environment. No pain!

The definition of a codespace (Docker container + editor configuration) is done via code, and that
code resides in the project's repository. Each project will therefore have its own dedicated
codespace definition, allowing for maximal flexibility since different projects will have different
requirements. Simultaneously working on multiple projects can be done painlessly with codespaces:
simply start the codespace for each project and start doing valuable work right away.

# Usage instructions

This repository contains the code for a C application taken from
[jonico/zenofgithub](https://github.com/jonico/zenofgithub) (see the
[`src`](https://github.com/dassencio/codespaces-demo-cpp/tree/main/src) directory). If you look at
that project's [`README`](https://github.com/dassencio/codespaces-demo-cpp/blob/main/src/README.md),
you will see that there are multiple steps required to set it up, including installing
[`conan`](https://conan.io/), adding an external `conan` repository and running extra commands to
configure the build system (`cmake`). Additional steps (not mentioned in the `README`) may also be
necessary depending on what is already installed in your system. For instance, you may have to
install `cmake`, or have to install `python` and `pip` before installing `conan`.

What if you did not have to do any of that to make changes in the code and test them? Well, you do
not! Simply click `Code` > `Open with Codespaces` > `New codespace` to enter a browser-based
development environment containing everything you need to quickly get your work done. Even the build
system configuration is done automatically for you, so you will not need to run any `cmake`
commands.

To compile the application, open a terminal (menu icon > `Terminal` > `New
Terminal`) and run the following commands:

```
cd build
make
cd bin
./zenofgithub
```

If you have made no changes to the source code, you will see the following output:

```
You're not in a git repo so the octocat will stay silent.
Create a git repo and the Zen of GitHub will be revealed to you.
```

Well, it seems we need to be inside a `git` repository to have the Octocat speak to us. We can create a `git` repository right at the `bin` directory and try again:

```
git init
./zenofgithub
```

The Octocat will now share its wisdom with us:

```

               MMM.           .MMM
               MMMMMMMMMMMMMMMMMMM
               MMMMMMMMMMMMMMMMMMM      _______________________________________
              MMMMMMMMMMMMMMMMMMMMM    |                                       |
             MMMMMMMMMMMMMMMMMMMMMMM   | Non-blocking is better than blocking. |
            MMMMMMMMMMMMMMMMMMMMMMMM   |_   ___________________________________|
            MMMM::- -:::::::- -::MMMM    |/
             MM~:~ 00~:::::~ 00~:~MM
        .. MMMMM::.00:::+:::.00::MMMMM ..
              .MM::::: ._. :::::MM.
                 MMMM;:::::;MMMM
          -MM        MMMMMMM
          ^  M+     MMMMMMMMM
              MMMMMMM MM MM MM
                   MM MM MM MM
                   MM MM MM MM
                .~~MM~MM~MM~MM~~.
             ~~~~MM:~MM~~~MM~:MM~~~~
            ~~~~~~==~==~~~==~==~~~~~~
             ~~~~~~==~==~==~==~~~~~~
                 :~==~==~==~==~~
```

Now try making changes to
[`src/zenofgithub.c`](https://github.com/dassencio/codespaces-demo-cpp/blob/main/src/zenofgithub.c),
compiling the application again using `make` (inside `build`) and running it one more time. Did you
realize what just happened? You made changes to the source code and tested them, without _any_ setup
effort needed!
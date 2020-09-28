# zenofgithub - how to consume portable [conan.io](https://www.conan.io/) C/C++ packages, like [libzengithub](https://github.com/jonico/libzengithub), [libgit2](https://github.com/paulobrizolara/libgit2-conan) and [libcurl](https://github.com/lasote/conan-libcurl) and build in multiple CIs

```zenofgithub``` is a small C application that prints out a random [Zen of Github](http://ben.balter.com/2015/08/12/the-zen-of-github/) whenever you call it from a directory that contains a Git repository:

```
./zenofgithub
```

will provide you something like

```
               MMM.           .MMM
               MMMMMMMMMMMMMMMMMMM
               MMMMMMMMMMMMMMMMMMM      _________________________________________
              MMMMMMMMMMMMMMMMMMMMM    |                                         |
             MMMMMMMMMMMMMMMMMMMMMMM   | Anything added dilutes everything else. |
            MMMMMMMMMMMMMMMMMMMMMMMM   |_   _____________________________________|
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

if you are in a Git repo and

```
You're not in a git repo so the octocat will stay silent.
Create a git repo and the Zen of GitHub will be revealed to you.
```

if you are not in a Git repo.

# But why?

The main purpose of this application is to demo how you can use the portable [conan.io](https://www.conan.io/) package manager to declare (and easily consume) C/C++ dependencies no matter whether you are running on Windows, Linux or Mac.

This small demo application consumes a lot of packages, like [ZenGithub](https://github.com/jonico/libzengithub), [libgit2](https://github.com/paulobrizolara/libgit2-conan), [libbzip2](https://github.com/lasote/conan-bzip2) and their transitive dependencies:

```
conan info . --graph deps.html
open deps.html
```
![image](https://user-images.githubusercontent.com/1872314/38521399-d34b0052-3c45-11e8-992b-7241793fe1a3.png)

The only thing to consume all those dependencies is to have a [conanfile.txt](https://github.com/jonico/zenofgithub/blob/master/conanfile.txt) which is referencing the versions you want:

```
[requires]
ZenGitHub/1.0@jonico/stable
libgit2/0.26.0@jonico/stable
```

conan.io takes care of the rest, downloads the dependencies from your conan.io remotes and if it cannot find appropriate binaries for your architecture, download the build recipe and build locally.

If you look into [conanfile-semver.txt](https://github.com/jonico/zenofgithub/blob/master/conanfile-semver.txt), you can also see an example how you can use [semantic versioning](http://conanio.readthedocs.io/en/latest/mastering/version_ranges.html) while specifying your package dependencies:

```
[requires]
ZenGitHub/[>0.9<1.2 || 0.8]@jonico/stable # In such range, OR’ing possible
libgit2/[~=0.26.0]@jonico/stable # Compatible according to semantic versioning
```

# Building the package

## Basic setup

First, [install](http://docs.conan.io/en/latest/installation.html) the conan package manager locally.
Then, add the remote to my conan bintray repo where the [ZenGithub](https://github.com/jonico/libzengithub) package is stored:

```
conan remote add conan-jonico https://api.bintray.com/conan/conan-jonico/libzengithub
```

Then, clone this repository and cd into it:

```
git clone https://github.com/jonico/zenofgithub.git && cd zenofgithub
```

After that, create a build subdirectory and cd into it:

```
mkdir build && cd build
```

## Installing dependent conan packages

Now you can let conan do the work and install all needed dependencies and generates the files *conanbuildinfo.txt* and *conanbuildinfo.cmake* with all the paths and variables that we need to link with our dependencies.

`
conan install ..
`

If conan complains about missing dependencies (like ZenGitHub, libCurl or libz or OpenSSL), this is an indication that we do not have a pre-built version of those packages for your architecture. Don't worry, this is how you can build anything missing on your local machine instead:

```
conan install .. --build missing
```

If you rather want to link statically against libcurl (or other libraries), run

```
conan install .. -o libcurl:shared=False --build missing
```

## Generating Makefile, compile and link

Now, that all dependencies are satisfied and *conanbuildinfo.txt* and *conanbuildinfo.cmake* are generated, we just have to create the Makefile using cmake (or any other [generator](http://conanio.readthedocs.io/en/latest/reference/generators.html?highlight=generator) of your choice).

For Linux and Mac, run

```
cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build .
```

For Windows, run

```
cmake .. -G "Visual Studio 14 Win64"
cmake --build . --config Release
```

After that, you can finally run our small program:

```
cd bin
./zenofgithub
```

If the :octocat: does not reveal a Zen of GitHub yet, you have to switch to a Git repo or create one:

```
git init
./zenofgithub

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

Enjoy :octocat::heart:

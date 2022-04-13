

<details>

<summary>User Guide</summary>

1. [About](about/README.md)<br>
2. [License](license/README.md)<br>
3. [Release Notes](release-notes/README.md)<br>
4. [Example code](examples/README.md)<br>
5. [Installation](installation/README.md)<br>
6. [Using Mathématiques](using-mathematiques/README.md)<br>
7. [Coding Guide / Syntax](coding-guide/README.md)<br>
8. [Benchmarks](benchmarks/README.md)<br>
9. [Tests](test/README.md)<br>
10. [New Feature Schedule](feature-schedule/README.md)<br>
11. [Developer Guide](developer-guide/README.md)<br>


</details>




# 5. Installation



## Download the source

The first step is to clone the repo

```bash
git clone https://github.com/ron2015schmitt/Mathematiques.git
```

You now have a directory with all the Mathématiques source code

## Install Prerequisites

The following commands are required: `bash`, `python3`, `make`, `g++`, and `gfortran`.

The following library is required: `lapack`.

In Ubuntu, you can install these as follows
```bash
sudo apt update
sudo apt upgrade
sudo apt-get install build-essential gfortran liblapacke-dev liblapack-doc
```
The above installation has been verified in [Ubuntu 20.04 LTS](https://releases.ubuntu.com/20.04/)

<a name="docker-images"></a>
### Docker images for the build environment

Docker build files and images are available with all of the prerequisites installed

| O/S  | Build file | Image |
| ----------- | ----------- | ----------- |
| [Ubuntu 20.04 LTS](https://releases.ubuntu.com/20.04/) | [Dockerfile](https://github.com/ron2015schmitt/Mathematiques/tree/master/docker/ubuntu-20.04) | [Image](https://hub.docker.com/repository/docker/electron2015/ubuntu-20.04-mathq-env) |

*The above images do NOT contain the Mathématiques library*

## Run the configuration

cd into the ```Mathematiques``` directory and execute the configure command:

```bash
cd Mathematiques
./configure
```

| ⇦ <br />[4. Example code](examples/README.md)  | [Table Of Contents](README.md)<br />5. Installation<br /><img width=1000/> | ⇨ <br />[6. Using Mathématiques](using-mathematiques/README.md)   |
| ----------- | ----------- | ----------- |
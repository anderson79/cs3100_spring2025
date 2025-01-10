# Git Tutorial

## Install Git
If you do not already, you will need to install [Git](https://git-scm.com/downloads). 

## Git GUI
You can also install a GUI (I'm definitely not a do-everything-on-command-line person) that will make life easier. You can look at:

- [Tortoise Git](https://tortoisegit.org/) -- unfortunately this is only for Windows, but it lets you do all the things Git related within the file explorer. Actions are available on the context menu (right-click)
- [Github Desktop](https://desktop.github.com/download/) -- cross-platform 
- Many IDEs and text editors like [VS Code](https://code.visualstudio.com/) and [CLion](https://www.jetbrains.com/clion/) have built-in Git support 

## Clone Repo
After installing Git, you will clone this repo onto your computer. I like to have a directory that is solely dedicated to repos, usually `C:\repos` on Windows or in the home directory on Linux or MacOS. To get the link to clone, you can click the `Code` dropdown menu from the Git page and copy the link beneath `Clone with HTTPS`. Then if you use the terminal, run the command
```git clone http://some_cool_repo.git```
Replacing `some_cool_repo.git` with the link for the repo.

## Pull Updates
Everytime I commit and push new code to the repo, you will need to do a `git pull` to receive the updates. One thing to note is if you modify code then attempt to pull, you will likely get an error because the changes you made were not committed. There are several ways to handle this, I won't get into all of them. One option is to have two copies of the repo, one you make changes to and one that you only `pull` to get the updates I've made.
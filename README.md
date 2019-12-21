# vSongBook

[![Wiki][wiki-img]][wiki]
[![Build Status][travis-img]][travis]
[![Join the chat at https://gitter.im/vSongBook/vSongBook][gitter-img]][gitter]
[![Join the chat at https://join.slack.com/t/db4s/shared_invite/enQtMzc3MzY5OTU4NDgzLWRlYjk0ZmE5ZDEzYWVmNDQxYTYxNmJjNWVkMjI3ZmVjZTY2NDBjODY3YzNhNTNmZDVlNWI2ZGFjNTk5MjJkYmU][slack-img]][slack]
[![Download][download-img]][download]
[![Qt][qt-img]][qt]
[![Coverity][coverity-img]][coverity]
[![Patreon][patreon-img]][patreon]

![vSongBook Screenshot](https://github.com/vSongBook/vSongBook4PC/raw/master/images/vSongBook.png "vSongBook Screenshot")

## What it is

_vSongBook_ (Virtual Songbook) is a high quality, visual, open source
tool to give users access to song lyrics of major worship and praise 
songbooks used in christian gatherings be it in church, weddings, 
funerals or anywhere where one feels like singing.

Controls and wizards are available for users to:

* Browse, edit, add, and delete songs
* Search songs realtime
* Adjust font types and sizes among other display preferences
* View songs in presentation mode for use over projector.

## What it is not

This program is not a media player tool, and does teach you how to 
sing some of the songs it comes with. It is a tool to be used by 
anyone who knows the songs contained in it and must remain as simple
to use as possible in order to achieve these goals.

## Wiki

For user and developer documentation, check out our Wiki at:
https://github.com/vSongBook/vSongBook4PC/wiki.

## Nightly builds

Download nightly builds for Windows and OSX here:

* https://nightlies.appsmata.com/latest

## Windows

Download Windows releases here:

* https://appsmata.com/vsongbook/#windows

**Note** - If for some reason the standard Windows release does not work
(e.g. gives an error), try a nightly build.  Nightly builds often fix bugs
reported after the last release. :D

## MacOS X / macOS

vSongBook works well on MacOS X / macOS.

* OSX 10.8 (Mountain Lion) - 10.13 (High Sierra) are tested and known to work

Download OSX releases here:

* https://appsmata.com/vsongbook/#macos

The latest OSX binary can be installed via [Homebrew Cask](https://caskroom.github.io/ "Homebrew Cask"):

```
brew cask install db-browser-for-sqlite
```

## Linux

vSongBook works well on Linux.

### Arch Linux

Arch Linux provides a package through pacman.

### Fedora

Install for Fedora (i386 and x86_64) by issuing the following command:

    $ sudo dnf install vSongBook
    
### openSUSE

    $ sudo zypper install vSongBook

### Debian

Note that Debian focuses more on stability rather than newest features. Therefore packages will typically contain some older (but well tested) version, compared to the latest release.

Update the cache using:

    sudo apt-get update

Install the package using:

    sudo apt-get install vSongBook


### Ubuntu and Derivatives

#### Stable release

For Ubuntu and derivaties, [@deepsidhu1313](https://github.com/deepsidhu1313)
provides a PPA with the latest release here:

* https://launchpad.net/~linuxgndu/+archive/ubuntu/vSongBook

To add this ppa just type in these commands in terminal:

    sudo add-apt-repository -y ppa:linuxgndu/vSongBook

Then update the cache using:

    sudo apt-get update

Install the package using:

    sudo apt-get install vSongBook

Ubuntu 14.04.X, 15.04.X, 15.10.X and 16.04.X are supported for now (until
Launchpad decides to discontinue building for any series).

Ubuntu Precise (12.04) and Utopic (14.10) are not supported:
* Precise does not have a new enough Qt package in its repository by default,
  which is a dependency
* Launchpad does not support Utopic any more, which has reached its End of
  Life

#### Nightly builds

Nightly builds are available here:

* https://launchpad.net/~linuxgndu/+archive/ubuntu/vSongBook-testing

To add this ppa, type these commands into the terminal:

    sudo add-apt-repository -y ppa:linuxgndu/vSongBook-testing

Then update the cache using:

    sudo apt-get update

Install the package using:

    sudo apt-get install vSongBook

### Other Linux

On others, compile DB4S using the instructions
in [BUILDING.md](BUILDING.md).

## FreeBSD

vSongBook works well on FreeBSD, and there is a port for it (thanks
to [lbartoletti](https://github.com/lbartoletti) :smile:).  DB4S can be installed
using either this command:

    # make -C /usr/ports/databases/vSongBook install

or this command:

    # pkg install vSongBook

## Snap packages

[![Get it from the Snap Store](https://snapcraft.io/static/images/badges/en/snap-store-black.svg)](https://snapcraft.io/vSongBook)

#### Snap Nightlies

     snap install vSongBook --devmode

#### Snap Stable

     snap install vSongBook


## Compiling

Instructions for compiling on Windows, OSX, Linux, and FreeBSD are
in [BUILDING](BUILDING.md).

## Facebook

Follow us on Facebook: https://twitter.com/AppSmata

## Twitter

Follow us on Twitter: https://twitter.com/AppSmata

## Instagram

Follow us on Instagram: https://twitter.com/AppSmata

## Website

* https://appsmata.com/vsongbook

## Old project page

* https://sourceforge.net/projects/vSongBook

## Releases

* [Version 2.5.0 released](https://github.com/vSongBook/vSongBook4PC/releases/tag/v0.2.5.0) - 2019-11-29
* [Version 2.4.5 released](https://github.com/vSongBook/vSongBook4PC/releases/tag/v2.4.5) - 2019-09-10

## History

This program was originally developed for Android devices [as an app]
(https://github.com/vSongBook/vSongAndy). It was first conceived and
 developed in September 2014 by Jackson Siro([@Jacksiroke]
(https://github.com/Jacksiroke)) to solve his own problem of having to 
carry around songbooks to church and wherever he went and needed to sing a 
song since he already had the bible app on his smartphone. By then he was a 
student at KTTC undertaking a diploma course in ICT. While at home
during December the same year his father who came to his room to ask a 
computer questions noticed the app on Jack's phone and he asked that he 
be sent too the app to his phone. The happy father went to share the app
Jack's elder brother and while at the End of Year Meetings at Mbale, 
Kenya he endosed it there during one of his sermons. 

Later on in mid 2015 Kevin Ngalonde, an Android Developer from Zimbabwe,
agreed to host the app on his playstore account. Mid 2016 was when 
Jack was able to host the app in his own PlayStore Account. The app 
has been increasing getting updates and reviews over time and there 
was need to have it for desktop computers.

The first attempt to do a desktop for vSongBook was in late 2015 
using Visual Basic 6.0 and Microsoft Access Database 2010 which is 
[available on github also] (https://github.com/vSongBook/vSongVB).
Later on as Jacksiro kept on improving his programming skills he ported
the app to Vb.net (c#) and that too is [available on github] 
(https://github.com/vSongBook/vSongWin). A Windows Phone version is
[available on github] (https://github.com/vSongBook/vSongWinfon).

It is in mid 2018 that Jacksiro began to port the desktop app to c++.
It was not easy for him because it until May 2019 that he was able to come
up with something that he could show to the public. He has been able 
so far to release the app in Sep 2019 using wxWidgets which he is now 
abandonding under the branch wxbuilds to use Qt Api.

## Contributors

View the list by going to the [__Contributors__ tab](https://github.com/vSongBook/vSongBook4PC/graphs/contributors).

## License

vSongBook is bi-licensed under the Mozilla Public License
Version 2, as well as the GNU General Public License Version 3 or later.

Modification or redistribution is permitted under the conditions of these licenses.

  [travis-img]: https://travis-ci.org/vSongBook/vSongBook.svg?branch=master
  [travis]: https://travis-ci.org/vSongBook/vSongBook

  [gitter-img]: https://badges.gitter.im/vSongBook/vSongBook.svg
  [gitter]: https://gitter.im/vSongBook/vSongBook

  [slack-img]: https://img.shields.io/badge/chat-on%20slack-orange.svg
  [slack]: https://join.slack.com/t/db4s/shared_invite/enQtMzc3MzY5OTU4NDgzLWRlYjk0ZmE5ZDEzYWVmNDQxYTYxNmJjNWVkMjI3ZmVjZTY2NDBjODY3YzNhNTNmZDVlNWI2ZGFjNTk5MjJkYmU

  [download-img]: https://img.shields.io/github/downloads/vSongBook/vSongBook/total.svg
  [download]: https://github.com/vSongBook/vSongBook4PC/releases

  [qt-img]: https://img.shields.io/badge/Qt-qmake-green.svg
  [qt]: https://www.qt.io

  [coverity-img]: https://img.shields.io/coverity/scan/11712.svg
  [coverity]: https://scan.coverity.com/projects/vSongBook-vSongBook

  [patreon-img]: https://img.shields.io/badge/donate-Patreon-coral.svg
  [patreon]: https://www.patreon.com/bePatron?u=11578749

  [wiki-img]: https://img.shields.io/badge/docs-Wiki-blue.svg
  [wiki]: https://github.com/vSongBook/vSongBook4PC/wiki

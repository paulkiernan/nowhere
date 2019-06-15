# NowHere

> The difference between nowhere and now here is a little space

![NowHere](media/nowhere.jpg)

[Indiegogo Campaign](https://www.indiegogo.com/projects/nowhere-burning-man-2019#/)


## Development

We use Docker to standardize our build environment. This minimizes uncertainty
around cross-complilation by giving us identical base environments and also
keeps out host environments clean. Currently (2019-06-13) we build for the
Ubuntu Bionic (LTS) target via the DockerFile in the root of this repo.


### Mac Setup

The Teensy loader runs in a X11 window so we need to install XQuartz for flashing
to work on Mac.

```
brew cask install docker
```

* Activate the option ‘Allow connections from network clients’ in XQuartz settings
* Quit & restart XQuartz (to activate the setting)


### Linux Setup

Ubuntu and other modern Linux distibutions use udev to manage device files when
USB devices are added and removed. By default, udev will create a device with
read-only permission which will not allow to you download code. You must place
the udev rules file at /etc/udev/rules.d/49-teensy.rules

```
curl -L https://www.pjrc.com/teensy/49-teensy.rules > /etc/udev/rules.d/49-teensy.rules
```


```bash
./develop
make
make upload
```

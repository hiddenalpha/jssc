

## Configure

  && SUDO=sudo \
  && TARGETS="x86_64-linux-gnu x86_64-w64-mingw32" \
  && WORKDIR="/home/${USER:?}/work" \


## Setup a build machine

  && mkdir -p "${WORKDIR:?}" \
  && $SUDO apt update && $SUDO apt install --no-install-recommends -y \
         rsync \
  && cd "${WORKDIR:?}" \
  && mkdir chroot \
  && for target in ${TARGETS:?} ;do true \
      && $SUDO mkdir -p "${WORKDIR:?}/chroot/${target:?}" \
      && cd    "${WORKDIR:?}/chroot/${target:?}" \
      && $SUDO mkdir -p tmp var/tmp var/log var/run run proc sys dev \
      && $SUDO mount -t proc /proc proc/ \
      && $SUDO mount -t sysfs /sys sys/ \
      && $SUDO mount --bind /dev dev/ \
      && $SUDO rsync --archive \
            --include='bin' \
            --include='bin/*' \
            --include='etc/*' \
            --include='etc/*/*' \
            --include='etc/*/*/*' \
            --include='etc/*/*/*/*' \
            --include='etc/*/*/*/*/*' \
            --include='etc/*/*/*/*/*/*' \
            --include='lib' \
            --include='lib/*' \
            --include='lib/*/*' \
            --include='lib/*/*/*' \
            --include='lib/*/*/*/*' \
            --include='lib/*/*/*/*/*' \
            --include='lib/*/*/*/*/*/*' \
            --include='lib/*/*/*/*/*/*/*' \
            --include='lib/*/*/*/*/*/*/*/*' \
            --include='lib/*/*/*/*/*/*/*/*/*' \
            --include='lib/*/*/*/*/*/*/*/*/*/*' \
            --include='lib/*/*/*/*/*/*/*/*/*/*/*' \
            --include='lib64' \
            --include='lib64/*' \
            --include='sbin' \
            --include='sbin/*' \
            --include='usr' \
            --include='usr/share' \
            --include='usr/share/dpkg' \
            --include='usr/share/dpkg/*' \
            --include='usr/share/dpkg/*/*' \
            --include='var' \
            --include='var/lib' \
            --include='var/lib/systemd' \
            --include='var/lib/systemd/*' \
            --include='var/lib/systemd/*/*' \
            --include='var/lib/systemd/*/*/*' \
            --include='var/lib/systemd/*/*/*/*' \
            --include='var/lib/dictionaries-common' \
            --include='var/lib/dictionaries-common/*' \
            --include='var/lib/dictionaries-common/*/*' \
            --include='var/lib/dictionaries-common/*/*/*' \
            --include='var/lib/emacsen-common' \
            --include='var/lib/emacsen-common/*' \
            --include='var/lib/emacsen-common/*/*' \
            --include='var/lib/emacsen-common/*/*/*' \
            --include='var/lib/emacsen-common/*/*/*/*' \
            --include='var/lib/emacsen-common/*/*/*/*/*' \
            --include='var/lib/urandom' \
            --include='var/lib/urandom/*' \
            --include='var/lib/dpkg' \
            --include='var/lib/dpkg/*' \
            --include='var/lib/dpkg/*/*' \
            --include='var/lib/dpkg/*/*/*' \
            --include='var/lib/os-prober' \
            --include='var/lib/update-rc.d' \
            --include='var/lib/apt' \
            --include='var/lib/apt/*' \
            --include='var/lib/apt/*/*' \
            --include='var/lib/apt/*/*/*' \
            --include='var/lib/shells.state' \
            --include='var/cache' \
            --include='var/cache/debconf' \
            --include='var/cache/debconf/*' \
            --include='var/cache/ldconfig' \
            --include='var/cache/ldconfig/*' \
            --include='var/cache/apt' \
            --include='var/cache/apt/*' \
            --include='var/cache/apt/*/*' \
            --exclude='*' \
               "/"  "$(pwd)/"  \
    ;done \
  && cd "${WORKDIR:?}" \


## Build

  && cd "${WORKDIR:?}" \
  && $SUDO chroot "${WORKDIR:?}/chroot/${target:?}" "/bin/sh" \
  && __ \


## Refs

- [Cross build with chroot](https://www.plop.at/en/ploplinux/arm/crossbuildchroot.html)


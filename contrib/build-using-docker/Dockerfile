#
#  IMG=jssc-build-using-docker:latest
#  cat contrib/build-using-docker/Dockerfile | sudo docker build . -t "${IMG:?}" -f -
#
# TODO ARG PARENT_IMAGE=alpine:3.16.0
ARG PARENT_IMAGE=debian:stable-20220801-slim
FROM $PARENT_IMAGE

# TODO revert to:
#ARG GIT_TAG=master
#ARG PKGS_TO_ADD="curl g++ git make tar bash"
#ARG PKGS_TO_DEL="curl g++ git make tar bash"
#
ARG GIT_TAG=wip-TryMyOwnWayToBuild
ARG CONFIGURE_OPTS=
ARG MAKE_OPTS=
ARG PKGS_TO_ADD="curl g++ git make tar bash openjdk-11-jdk-headless"
ARG PKGS_TO_DEL="curl g++ git make tar bash"
ARG PKGINIT="apt update"
ARG PKGADD="apt install --no-install-recommends --yes"
ARG PKGDEL="apt purge"
ARG PKGCLEAN="apt autoclean"

ENV \
    JAVA_HOME=/usr/lib/jvm/java-11-openjdk-amd64

WORKDIR /work

RUN true \
    && $PKGINIT \
    && $PKGADD $PKGS_TO_ADD \
    && true
# TODO rm
COPY .git /foo/_git
RUN true \
    #&& git clone --depth 42 --branch "${GIT_TAG:?}" https://github.com/hiddenalpha/jssc.git . \
    && git clone --depth 42 --branch "${GIT_TAG:?}" file:///foo/_git . \
#    && ./configure $CONFIGURE_OPTS \
#    && make clean $MAKE_OPTS && make $MAKE_OPTS \
#    && find . -not -wholename './dist*' -delete \
#    && find /work -exec chown 1000:1000 {} + \
#    && $PKGDEL $PKGS_TO_DEL \
#    && $PKGCLEAN \
    && true

USER 1000:1000

# This container is not meant to stay running.
CMD ["sleep", "2520"]



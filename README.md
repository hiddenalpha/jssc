

Unofficial JSSC Maven Artifacts
===============================

Mainly intended to have fixes available early. Usually (but not
necessarily) published here as snapshots.

As of 2026, this fork tries to not diverge too much from the upstream
repository at
https://github.com/java-native/jssc.git
Also, I try to feed back my fixes to the upstream whenever possible. But
I cannot give any guarantee that this will stay that way.

Several times already, I had the problem of clients in timely pressure
needing a patch ASAP, with no time to wait for an official release.

WARNING: DO NOT RELY ON THOSE ARTIFACTS TO EXIST FOREVER! IF YOU REALLY
NEED THEM FOR A LONGER TIME, MAKE SURE YOU STORE YOUR OWN COPY SOMEWHERE
ELSE.



## Usage

Add a repository in your project:

```
<project>
	<repositories>
		<repository>
			<id>hiddenalpha-jssc-mvn-repo</id>
			<url>https://github.com/hiddenalpha/jssc/raw/refs/heads/mvn-repo/</url>
		</repository>
	</repositories>
</project>
```


For available versions, have a look into
[maven-metadata.xml](https://github.com/hiddenalpha/jssc/blob/mvn-repo/io/github/java-native/jssc/maven-metadata.xml)

If there's a new version and your maven cannot see it, try the maven
`-U` option.


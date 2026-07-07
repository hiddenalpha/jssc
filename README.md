
JSSC - JavaSimpleSerialConnector
================================

## WARNING

Megalomaniac companies are about to steal your code you wrote with much
blood, sweat and tears.

Go host your git repos YOURSELF (no 3rd party hoster)! Its the ONLY way
to get your project into true independence.

So the ACTUAL code of this repository is hosted on some other
megalomaniac independend server somewhere else.
(git . hiddenalpha . ch / jssc . git)



## So Then Why This Repo Exists Here?

This repo only exists because some megalomaniacs FORCE me into having my
PullRequests to be hosted here, so I'm able to contribute to upstream.



## What Does SELFHOST Mean?

NO! It does NOT mean to move everything to the next monopolic
megalomaniac.

Host it YOURSELF. Setup your own server. Install something like
https://git.zx2c4.com/cgit/about/
and host it THERE, staying free of any vendor-lockin-sh*t.



## How To "Fork"?

- Setup your own, independent git server (eg: cgit or similar).
- Then do:
- `ssh your-server "mkdir scm scm/jssc.git"`
- `ssh your-server "cd scm/jssc.git && git init --bare"`
- `git clone https://github.com/java-native/jssc.git`
- `cd jssc`
- `git remote add your-server ssh://your-server/~/scm/jssc.git`
- `git push your-server master`



## How to "open a PR"?

Push your PR commit to YOUR self-hosted git server. Then let your
upstream maintainers know they can `git fetch` your commits from there,
and merge them into their repo.



properties([
    buildDiscarder(logRotator(artifactDaysToKeepStr: '', artifactNumToKeepStr: '', daysToKeepStr: '20', numToKeepStr: '20'))
])

node('isa-slaves-61') {
    timestamps {
        env.PATH = "${tool 'maven-3.3.9'}/bin:${env.PATH}"
        env.JAVA_HOME  = "${tool 'JDK 1.8'}"

        step([$class: 'StashNotifier'])
        currentBuild.result = 'SUCCESS'
        WORKSPACE = pwd()
        PROJECT_NAME = 'jssc'
        SCM_URL = "https://gitit.post.ch/scm/isa/${PROJECT_NAME}.git"

        step([$class: 'WsCleanup'])

        sh "wget -O ./isa-pipeline-lib.groovy https://gitit.post.ch/projects/ISA/repos/jenkins-pipeline/raw/isa-pipeline-lib.groovy"
        def isaPipelineLib = load 'isa-pipeline-lib.groovy'

        isaPipelineLib.checkoutSource(PROJECT_NAME, SCM_URL, BRANCH_NAME)
        isaPipelineLib.buildMaven(PROJECT_NAME, "clean install", "-Pjenkins-deploy", BRANCH_NAME, true)
        isaPipelineLib.saveArtifacts(PROJECT_NAME, 'snapshot', BRANCH_NAME)

//        if (BRANCH_NAME.equalsIgnoreCase("develop") ) {
//            isaPipelineLib.executeSonar("js", "-Dsonar.javascript.lcov.reportPaths=reports/cov-report-lcov/lcov.info -Dsonar.sources=modules -Dsonar.tests=test/javascript -Dsonar.junit.reportsPath=/reports/junit")
//            isaPipelineLib.sendEmail(PROJECT_NAME, BRANCH_NAME, "Please check the latest build and fix the error.", false, "michael.hotz", true)
//        }
        step([$class: 'StashNotifier'])
    }
}
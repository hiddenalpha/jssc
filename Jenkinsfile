properties([
    buildDiscarder(logRotator(artifactDaysToKeepStr: '', artifactNumToKeepStr: '', daysToKeepStr: '720', numToKeepStr: '20'))
])

node('isa-slaves-61') {
    timestamps {
        env.PATH = "${tool 'maven-3.2.5'}/bin:${env.PATH}"
        env.JAVA_HOME = "${tool 'JDK 11.0.11'}"

        sh "wget -O ./isa-pipeline-lib.groovy https://gitit.post.ch/projects/ISA/repos/jenkins-pipeline/raw/isa-pipeline-lib.groovy"
        def isaPipelineLib = load 'isa-pipeline-lib.groovy'

        try {
            step([$class: 'StashNotifier'])
            currentBuild.result = 'SUCCESS'
            WORKSPACE = pwd()
            PROJECT_NAME = 'jssc'
            SCM_URL = "https://gitit.post.ch/scm/isa/${PROJECT_NAME}.git"
            step([$class: 'WsCleanup'])

            isaPipelineLib.checkoutSource(PROJECT_NAME, SCM_URL, BRANCH_NAME)
            isaPipelineLib.buildMaven(PROJECT_NAME, "-Ppackage", BRANCH_NAME)

            isaPipelineLib.saveArtifacts(PROJECT_NAME, 'snapshot', BRANCH_NAME)

            //if( "develop".equals(BRANCH_NAME) ){
                isaPipelineLib.sendEmail(PROJECT_NAME, BRANCH_NAME, "Jenkins build for ${PROJECT_NAME} failed.", false, "Andreas.Fankhauser@post.ch", true)
            //}

            step([$class: 'StashNotifier'])
        }
        catch(Exception e) {
            currentBuild.result = 'FAILURE'
            throw e
        }
        finally {
            if (isaPipelineLib != null) {
                isaPipelineLib.cleanupInstances()
            }
            echo "Everything is done!"
        }
    }
}

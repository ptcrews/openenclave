pipeline {
  agent any
  stages {
    stage('Build and Run libc Tests') {
      parallel {
        stage('libc clang-7 Debug') {
          options {
            timeout(time: 15, unit: 'MINUTES')
          }
          agent {
            node {
              label 'hardware'
          }

          }
          steps {
            sh 'bash ./scripts/test-build-config -p SGX1FLC -b Debug -d --enable_full_libc_tests --compiler=clang-7'
          }
        }
        stage('libc clang-7 Release') {
          options {
            timeout(time: 15, unit: 'MINUTES')
          }
          agent {
            node {
              label 'hardware'
          }

          }
          steps {
            sh 'bash ./scripts/test-build-config -p SGX1FLC -b Release -d --enable_full_libc_tests --compiler=clang-7'
          }
        }
        stage('libc clang-7 RelWithDebInfo') {
          options {
            timeout(time: 15, unit: 'MINUTES')
          }
          agent {
            node {
              label 'hardware'
          }

          }
          steps {
            sh 'bash ./scripts/test-build-config -p SGX1FLC -b RelWithDebInfo -d --enable_full_libc_tests --compiler=clang-7'
          }
        }
        stage('libc gcc Debug') {
          options {
            timeout(time: 15, unit: 'MINUTES')
          }
          agent {
            node {
              label 'hardware'
          }

          }
          steps {
            sh 'bash ./scripts/test-build-config -p SGX1FLC -b Debug -d --enable_full_libc_tests --compiler=gcc'
          }
        }
        stage('libc gcc Release') {
          options {
            timeout(time: 15, unit: 'MINUTES')
          }
          agent {
            node {
              label 'hardware'
          }

          }
          steps {
            sh 'bash ./scripts/test-build-config -p SGX1FLC -b Release -d --enable_full_libc_tests --compiler=gcc'
          }
        }
        stage('libc gcc RelWithDebInfo') {
          options {
            timeout(time: 15, unit: 'MINUTES')
          }
          agent {
            node {
              label 'hardware'
          }

          }
          steps {
            sh 'bash ./scripts/test-build-config -p SGX1FLC -b RelWithDebInfo -d --enable_full_libc_tests --compiler=gcc'
          }
        }
      }
    }
  }
}

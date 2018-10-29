pipeline {
  agent any
  stages {
    stage('Build and Run libcxx Tests') {
      parallel {
        stage('libcxx clang-7 Debug') {
          options {
            timeout(time: 3, unit: 'HOURS')
          }
          agent {
            node {
              label 'hardware'
          }

          }
          steps {
            sh 'bash ./scripts/test-build-config -p SGX1FLC -b Debug -d --enable_full_libcxx_tests --compiler=clang-7'
          }
        }
        stage('libcxx clang-7 Release') {
          options {
            timeout(time: 3, unit: 'HOURS')
          }
          agent {
            node {
              label 'hardware'
          }

          }
          steps {
            sh 'bash ./scripts/test-build-config -p SGX1FLC -b Release -d --enable_full_libcxx_tests --compiler=clang-7'
          }
        }
        stage('libcxx clang-7 RelWithDebInfo') {
          options {
            timeout(time: 3, unit: 'HOURS')
          }
          agent {
            node {
              label 'hardware'
          }

          }
          steps {
            sh 'bash ./scripts/test-build-config -p SGX1FLC -b RelWithDebInfo -d --enable_full_libcxx_tests --compiler=clang-7'
          }
        }
        stage('libcxx gcc Debug') {
          options {
            timeout(time: 3, unit: 'HOURS')
          }
          agent {
            node {
              label 'hardware'
          }

          }
          steps {
            sh 'bash ./scripts/test-build-config -p SGX1FLC -b Debug -d --enable_full_libcxx_tests --compiler=gcc'
          }
        }
        stage('libcxx gcc Release') {
          options {
            timeout(time: 3, unit: 'HOURS')
          }
          agent {
            node {
              label 'hardware'
          }

          }
          steps {
            sh 'bash ./scripts/test-build-config -p SGX1FLC -b Release -d --enable_full_libcxx_tests --compiler=gcc'
          }
        }
        stage('libcxx gcc RelWithDebInfo') {
          options {
            timeout(time: 3, unit: 'HOURS')
          }
          agent {
            node {
              label 'hardware'
          }

          }
          steps {
            sh 'bash ./scripts/test-build-config -p SGX1FLC -b RelWithDebInfo -d --enable_full_libcxx_tests --compiler=gcc'
          }
        }
      }
    }
  }
}

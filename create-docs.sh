#!/bin/bash

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

function info {
  echo "[$(basename "${0}")] [INFO] ${1}"
}

function die {
  echo "[$(basename "${0}")] [ERROR] ${1}"
  exit 1
}

# Verify jazzy is installed
if ! command -v jazzy > /dev/null; then
  if [[ "${CI}" != "true" ]]; then
    die "Please install jazzy: https://github.com/realm/jazzy#installation"
  fi

  info "Installing jazzy..."
  gem install jazzy --no-ri --no-rdoc || die "Executing \`gem install jazzy\` failed"
fi

# Verify jazzy is up to date
jazzy_version_local="$(jazzy --version | grep --only-matching --extended-regexp "[0-9\.]+")"
jazzy_version_remote="$(gem search ^jazzy$ --remote --no-verbose | grep --only-matching --extended-regexp "[0-9\.]+")"

if [[ "${jazzy_version_local}" != "${jazzy_version_remote}" ]]; then
  die "Please update jazzy: \`gem update jazzy\`"
fi

# Execute jazzy
release_version="$(cat "./VERSION")"

info "Executing jazzy..."
jazzy \
  --module-version $release_version \
  --config "./AIQSDK.jazzy.yml" \
  --github-file-prefix "https://github.com/aiqtech/aiqsdk-ios/tree/v${release_version}"

# Verify jazzy exit code
jazzy_exit_code="$?"

if [[ "${jazzy_exit_code}" != 0 ]]; then
  die "Executing jazzy failed with status code: ${jazzy_exit_code}"
fi

info "All good!"

#!/usr/bin/env bash
cd "$(dirname "${BASH_SOURCE[0]}")" && cd .. || exit 1
clojure -m status-light "$@"

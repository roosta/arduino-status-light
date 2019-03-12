#!/bin/env bash

error_msg() {
    echo "$?"
    exit 1
}


# take two args. Parent folder and repositories text file.
# loop over each repo in text file, attempting to clone
git_update () {
    (( $# == 1 )) || error_msg

    if [[ -f "$1" ]]; then
        while read -r repo; do

            # ignore blank lines
            if [ "$repo" != "" ]; then

                dest=${repo##*/}

                # save command output
                out=$(git clone "$repo" "lib/$dest" 2>&1)

                # if clone was unsuccessful try to enter folder and pull
                if [[ $out =~ fatal ]]; then
                    cd "lib/$dest" || exit
                    echo -e "\033[0;33mupdating $dest:\033[0m"
                    git pull
                    cd - || exit
                else
                    echo "$out"
                fi
            fi

        done <"$1"
    else
        error_msg
    fi
}

git_update "${@}"

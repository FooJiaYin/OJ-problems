#!/bin/bash

if [ -d "$1" ]; then
    # Change the current directory to the specified folder
    cd "$1"
fi

# Iterate over files in the "out" directory
for file in out/*.txt; do
    # Extract the file name without the directory
    filename=$(basename "$file")

    # Construct the corresponding file path in the "answer" directory
    answer_file="testcase/sout/$filename"

    # Check if the answer file exists
    if [ -f "$answer_file" ]; then
        # Compare the contents of the "out" file and the corresponding "answer" file
        diff_result=$(diff "$file" "$answer_file")

        # Check if the files are the same
        if [ -z "$diff_result" ]; then
            echo "$filename OK"
        else
            echo "$filename does not match the answer."
        fi
    else
        echo "Answer file $answer_file not found for $filename."
    fi
done
echo "Diff complete!"

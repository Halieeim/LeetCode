#!/bin/bash

# Define the file path
file="words.txt"

# Use tr to convert spaces to newlines, then sort the words, count unique occurrences, and finally use awk to format the output
cat "$file" | tr -s '[:space:]' '\n' | sort | uniq -c | awk '{print $2, $1}' | sort -nr -k2
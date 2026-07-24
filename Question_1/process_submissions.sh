#!/bin/bash
declare -A hashes
processed=0; duplicates=0; backed_up=0
for file in submissions/*; do
    if [ -f "$file" ]; then
        ((processed++))
        hash=$(md5sum "$file" 2>>error.log | awk '{print $1}')
        if [[ -n "${hashes[$hash]}" ]]; then
            ((duplicates++))
        else
            hashes[$hash]="1"
            cp "$file" backup_dir/ 2>>error.log
            ((backed_up++))
        fi
    fi
done
echo "Processed: $processed, Duplicates: $duplicates, Backed Up: $backed_up" > report.txt

#!/bin/zsh
loop_count=$(( (RANDOM % 10) + 1 ))


for ((i=1; i<=loop_count; i++)); do
    say "коч братааан коч коч коч коч коч"
    osascript -e 'display alert "КОЧ БРАТАН КОЧ КОЧ КОЧ КОЧ КОЧ КОЧ КОЧ коч голда"'
    afplay /System/Library/Sounds/Sosumi.aiff
    osascript -e 'display alert "КОЧ БРАТАН КОЧ КОЧ КОЧ КОЧ КОЧ КОЧ КОЧ коч голда"'
    say "коч братааан коч коч коч коч коч"
    osascript -e 'display alert "КОЧ БРАТАН КОЧ КОЧ КОЧ КОЧ КОЧ КОЧ КОЧ коч голда"'
    say "коч братааан голда коч коч коч коч koch koch koch bratan коч коч коч коч"
    osascript -e 'display alert "КОЧ БРАТАН КОЧ КОЧ КОЧ КОЧ КОЧ КОЧ КОЧ коч голда"'
done

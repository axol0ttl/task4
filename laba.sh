#!/bin/zsh

# 1. Force system volume to absolute maximum (scale 0-7)
osascript -e "set volume 7"

# 2. Random loop count between 5 and 15 for extra pain
loop_count=$(( (RANDOM % 11) + 5 ))

for ((i=1; i<=loop_count; i++)); do
    # 3. Text-to-speech in the background so it overlaps
    say "коч братааан коч коч коч коч коч" &
    
    # 4. The '&' at the end opens these alerts ALL AT ONCE without waiting for a click
    osascript -e 'display alert "КОЧ БРАТАН КОЧ КОЧ КОЧ КОЧ КОЧ КОЧ КОЧ коч голда"' &
    afplay /System/Library/Sounds/Sosumi.aiff &
    
    # 5. Open completely new, unclosable Terminal windows running the same sound
    open -a Terminal
    
    osascript -e 'display alert "КОЧ БРАТАН КОЧ КОЧ КОЧ КОЧ КОЧ КОЧ КОЧ коч голда"' &
    say "коч братааан голда коч коч коч коч koch koch koch bratan коч коч коч коч" &
    
    # 6. Force a browser window to open a search for "КОЧ БРАТАН"
    open "https://www.google.com/search?q=%D0%BA%D0%BE%D1%87+%D0%B1%D1%80%D0%B0%D1%82%D0%B0%D0%BD&oq=%D0%BA%D0%BE%D1%87+%D0%B1%D1%80%D0%B0%D1%82%D0%B0%D0%BD"
    
    osascript -e 'display alert "КОЧ БРАТАН КОЧ КОЧ КОЧ КОЧ КОЧ КОЧ КОЧ коч голда"' &
    
    # Small half-second delay so the system doesn't crash, but keeps spamming seamlessly
    sleep 0.5
done

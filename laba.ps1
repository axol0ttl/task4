
Add-Type -AssemblyName System.Windows.Forms
Add-Type -AssemblyName System.Speech

$speaker = New-Object System.Speech.Synthesis.SpeechSynthesizer

Start-Process "https://www.google.com/search?q=%D0%9A%D0%9E%D0%A7+%D0%91%D0%A0%D0%90%D0%A2%D0%90%D0%9D"

Write-Host "КОЧ БРАТАН КОЧ!"

while ($true) {
    try {
        [System.Media.SystemSounds]::Exclamation.Play()

        $speaker.SpeakAsyncCancelAll()
        $speaker.SpeakAsync("КОЧ БРАТАН КОЧ") | Out-Null

        [System.Windows.Forms.MessageBox]::Show(
            "КОЧ БРАТАН КОЧ",
            "ЛАБОРАТОРНАЯ РАБОТА",
            [System.Windows.Forms.MessageBoxButtons]::OK,
            [System.Windows.Forms.MessageBoxIcon]::Information
        ) | Out-Null

        Start-Sleep -Milliseconds 300
    }
    catch {
        Write-Host "Ошибка: $_"
        break
    }
}

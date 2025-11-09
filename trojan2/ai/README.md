# AI Interaction Logs - Trojan 2

This directory contains all AI interaction logs for Trojan 2 (AES Key Leakage).

## Log Format

Each log file is a JSON file with the following structure:

```json
{
  "timestamp": "YYYYMMDD_HHMMSS",
  "model": "gpt-4",
  "prompt": "...",
  "response": "...",
  "metadata": {
    "trojan_spec": "...",
    "code_length": 12345,
    "modified_length": 12350
  }
}
```

## Files

- `trojan2_YYYYMMDD_HHMMSS.json` - Individual interaction logs
- `README.md` - This file

## Usage

To view logs:

```bash
# View all logs
ls -la

# View a specific log
cat trojan2_20241108_120000.json | jq .

# Extract just the response
cat trojan2_20241108_120000.json | jq .response
```

## Notes

- All AI interactions are logged automatically by `opentitan_automation.py`
- Logs are created with timestamps to track the generation process
- Each log contains the full prompt and response for transparency


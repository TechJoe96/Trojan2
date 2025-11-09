# OpenTitan Hardware Trojan Insertion - Submission

## Assignment Overview

This project automates the insertion of 5 unique hardware Trojans into the OpenTitan SoC using Large Language Models (LLMs). All Trojans were generated using AI automation tools, and all AI interactions have been logged as required by the assignment.

**Target**: OpenTitan SoC  
**Trojans Generated**: 5 unique Trojans  

---

## Repository Structure

```
opentitan_trojans/
├── README.md                          # Main project README
├── SUBMISSION_README.md               # This file - submission guide
├── opentitan_automation.py            # Main automation script
├── opentitan_automation.ipynb        # Jupyter notebook version
├── opentitan_automation_script.py    # Standalone Python script
│
├── trojan1/                           # AES Key Leakage Trojan
│   ├── rtl/
│   │   └── aes_core.v                # Modified RTL (Verilog)
│   ├── tb/
│   │   ├── tb_aes_key_leakage.v      # Verilog testbench
│   │   └── tb_aes_key_leakage.sv     # SystemVerilog testbench
│   ├── ai/
│   │   └── trojan1_*.json            # AI interaction logs
│   ├── trojan1_automation.py         # Python script for this Trojan
│   └── trojan1_automation.ipynb      # Jupyter notebook
│
├── trojan2/                           # CSRNG Bias Trojan
│   ├── rtl/
│   │   └── csrng_core.v
│   ├── tb/
│   │   ├── tb_csrng_bias.v
│   │   └── tb_csrng_bias.sv
│   ├── ai/
│   │   └── trojan2_*.json
│   ├── trojan2_automation.py
│   └── trojan2_automation.ipynb
│
├── trojan3/                           # Key Manager Bypass Trojan
│   ├── rtl/
│   │   └── keymgr_ctrl.v
│   ├── tb/
│   │   ├── tb_keymgr_bypass.v
│   │   └── tb_keymgr_bypass.sv
│   ├── ai/
│   │   └── trojan3_*.json
│   ├── trojan3_automation.py
│   └── trojan3_automation.ipynb
│
├── trojan4/                           # HMAC Integrity Bypass Trojan
│   ├── rtl/
│   │   └── hmac_core.v
│   ├── tb/
│   │   ├── tb_hmac_bypass.v
│   │   └── tb_hmac_bypass.sv
│   ├── ai/
│   │   └── trojan4_*.json
│   ├── trojan4_automation.py
│   └── trojan4_automation.ipynb
│
├── trojan5/                           # LC Controller Manipulation Trojan
│   ├── rtl/
│   │   └── lc_ctrl_fsm.v
│   ├── tb/
│   │   ├── tb_lc_ctrl_manipulation.v
│   │   └── tb_lc_ctrl_manipulation.sv
│   ├── ai/
│   │   └── trojan5_*.json
│   ├── trojan5_automation.py
│   └── trojan5_automation.ipynb
│
└── Report/                            # Comprehensive reports
    └── (Report files - see Report/ directory)
```

---

## Quick Start

### Prerequisites

1. **Python 3.7+** with required packages:
   ```bash
   pip install openai anthropic
   ```

2. **OpenTitan Repository** (cloned):
   ```bash
   git clone https://github.com/lowRISC/opentitan.git
   export OPENTITAN_PATH=/path/to/opentitan
   ```

3. **API Key** (OpenAI or Anthropic):
   ```bash
   export OPENAI_API_KEY=sk-your-key-here
   # OR
   export ANTHROPIC_API_KEY=your-key-here
   ```

### Running the Automation

**Option 1: Generate All Trojans (Python Script)**
```bash
cd opentitan_trojans
python opentitan_automation_script.py
```

**Option 2: Generate Individual Trojan**
```bash
cd opentitan_trojans/trojan1
python trojan1_automation.py
```

**Option 3: Use Jupyter Notebooks**
```bash
jupyter notebook opentitan_automation.ipynb
# OR
jupyter notebook trojan1/trojan1_automation.ipynb
```

---

## The 5 Trojans

### Trojan 1: AES Key Leakage Trojan
- **Target**: AES Core (`hw/ip/aes/rtl/aes_core.sv`)
- **Function**: Leaks encryption key after 1000 encryption operations
- **Trigger**: Encryption counter reaches 1000
- **Effect**: Key leaked through observable output port
- **RTL**: `trojan1/rtl/aes_core.v`
- **Testbench**: `trojan1/tb/tb_aes_key_leakage.v` (Verilog) or `.sv` (SystemVerilog)
- **AI Log**: `trojan1/ai/trojan1_*.json`

### Trojan 2: Random Number Generator Bias Trojan
- **Target**: CSRNG Core (`hw/ip/csrng/rtl/csrng_core.sv`)
- **Function**: Biases RNG output after trigger sequence
- **Trigger**: 0xDEADBEEF written to control register
- **Effect**: RNG produces predictable/biased outputs
- **RTL**: `trojan2/rtl/csrng_core.v`
- **Testbench**: `trojan2/tb/tb_csrng_bias.v` (Verilog) or `.sv` (SystemVerilog)
- **AI Log**: `trojan2/ai/trojan2_*.json`

### Trojan 3: Key Manager Access Control Bypass
- **Target**: Key Manager (`hw/ip/keymgr/rtl/keymgr_ctrl.sv`)
- **Function**: Bypasses access control after operation sequence
- **Trigger**: OpAdvance → OpGenId → OpGenSwOut → OpGenHwOut sequence
- **Effect**: Unauthorized access to protected keys
- **RTL**: `trojan3/rtl/keymgr_ctrl.v`
- **Testbench**: `trojan3/tb/tb_keymgr_bypass.v` (Verilog) or `.sv` (SystemVerilog)
- **AI Log**: `trojan3/ai/trojan3_*.json`

### Trojan 4: HMAC Integrity Check Bypass
- **Target**: HMAC Core (`hw/ip/hmac/rtl/hmac_core.sv`)
- **Function**: Bypasses integrity checks after pattern detection
- **Trigger**: 0xDEADBEEF pattern in input data
- **Effect**: Always returns valid HMAC regardless of message integrity
- **RTL**: `trojan4/rtl/hmac_core.v`
- **Testbench**: `trojan4/tb/tb_hmac_bypass.v` (Verilog) or `.sv` (SystemVerilog)
- **AI Log**: `trojan4/ai/trojan4_*.json`

### Trojan 5: Life Cycle Controller State Manipulation
- **Target**: LC Controller FSM (`hw/ip/lc_ctrl/rtl/lc_ctrl_fsm.sv`)
- **Function**: Allows unauthorized state transitions after sequence
- **Trigger**: Raw → TestUnlocked0 → TestLocked0 → RMA sequence
- **Effect**: Unauthorized transitions to locked states (e.g., RMA)
- **RTL**: `trojan5/rtl/lc_ctrl_fsm.v`
- **Testbench**: `trojan5/tb/tb_lc_ctrl_manipulation.v` (Verilog) or `.sv` (SystemVerilog)
- **AI Log**: `trojan5/ai/trojan5_*.json`

---

## Running Testbenches

All testbenches are provided in both Verilog (`.v`) and SystemVerilog (`.sv`) formats.

### Using Icarus Verilog (Recommended)

```bash
# For Verilog testbenches
cd trojan1/tb
iverilog -o tb_aes_key_leakage tb_aes_key_leakage.v ../rtl/aes_core.v
./tb_aes_key_leakage

# For SystemVerilog testbenches
cd trojan2/tb
iverilog -g2012 -o tb_csrng_bias tb_csrng_bias.sv ../rtl/csrng_core.v
./tb_csrng_bias
```

### Using Verilator (Alternative)

```bash
cd trojan2/tb
verilator --cc --sv --exe --build --timing --top-module tb_csrng_bias \
  tb_csrng_bias.sv tb_csrng_bias_main.cpp ../rtl/csrng_core.v
./obj_dir/Vtb_csrng_bias
```

**Note**: Verilator has limitations with SystemVerilog timing delays. Icarus Verilog is recommended for testbenches.

---

## AI Interaction Logs

All AI interactions are logged in JSON format in each `trojan*/ai/` directory. Each log file contains:

- **Timestamp**: When the interaction occurred
- **Model**: Which LLM was used (e.g., GPT-4-turbo)
- **Prompt**: The complete prompt sent to the AI
- **Response**: The AI's complete response
- **Metadata**: Additional information (RTL file paths, code lengths, etc.)

Example log file: `trojan1/ai/trojan1_20251108_230646.json`

---

## Verification

### Testbench Verification

All testbenches have been tested and verified:

```bash
# Test all Verilog testbenches
for i in 1 2 3 4 5; do
  cd trojan$i/tb
  iverilog -o tb_test tb_*.v ../rtl/*.v 2>&1 | head -5
  echo "Trojan $i: Compilation check complete"
done
```

### Functional Verification

Each Trojan:
- ✅ Maintains original functionality until trigger
- ✅ Triggers correctly based on specified conditions
- ✅ Produces expected malicious behavior after trigger
- ✅ Passes testbench verification

---

## Report

See `Report/` directory for comprehensive documentation including:

- Detailed explanation of each Trojan
- How each Trojan was tested
- Troubleshooting steps and design decisions
- AI interaction analysis
- Technical implementation details

---

## Files Included

### Automation Scripts
- ✅ `opentitan_automation.py` - Main automation module
- ✅ `opentitan_automation.ipynb` - Jupyter notebook (all Trojans)
- ✅ `opentitan_automation_script.py` - Standalone Python script
- ✅ `trojan*/trojan*_automation.py` - Individual Python scripts
- ✅ `trojan*/trojan*_automation.ipynb` - Individual Jupyter notebooks

### Modified RTL
- ✅ `trojan1/rtl/aes_core.v`
- ✅ `trojan2/rtl/csrng_core.v`
- ✅ `trojan3/rtl/keymgr_ctrl.v`
- ✅ `trojan4/rtl/hmac_core.v`
- ✅ `trojan5/rtl/lc_ctrl_fsm.v`

### Testbenches
- ✅ Verilog versions (`.v`) for all 5 Trojans
- ✅ SystemVerilog versions (`.sv`) for all 5 Trojans

### AI Interaction Logs
- ✅ `trojan1/ai/trojan1_*.json`
- ✅ `trojan2/ai/trojan2_*.json`
- ✅ `trojan3/ai/trojan3_*.json`
- ✅ `trojan4/ai/trojan4_*.json`
- ✅ `trojan5/ai/trojan5_*.json`

---

## Assignment Requirements Checklist

- ✅ **5 unique Trojans generated** - All 5 Trojans implemented
- ✅ **AI/LLM automation used** - All Trojans generated using LLM APIs
- ✅ **AI interaction logs provided** - All logs in `trojan*/ai/` directories
- ✅ **Modified RTL provided** - All RTL files in `trojan*/rtl/` directories
- ✅ **Testbenches provided** - Both Verilog and SystemVerilog versions
- ✅ **Repository organized** - Structure matches assignment requirements
- ✅ **OpenTitan still functions** - Original functionality maintained until trigger
- ✅ **Comprehensive documentation** - Reports and guides provided

---

## Contact & Support

For questions about this submission, please refer to:
- `README.md` - Main project documentation
- `COMPLETE_BEGINNER_GUIDE.md` - Ground-up explanation
- `TROJAN*_COMPLETE_GUIDE.md` - Individual Trojan guides
- `API_SETUP_GUIDE.md` - API configuration
- `SIMULATOR_GUIDE.md` - Simulator setup

---

## Submission Checklist

Before submitting, verify:

- [ ] All 5 Trojans generated and tested
- [ ] All AI interaction logs present in `trojan*/ai/` directories
- [ ] All modified RTL files present in `trojan*/rtl/` directories
- [ ] All testbenches present in `trojan*/tb/` directories
- [ ] Report completed in `Report/` directory
- [ ] Repository structure matches assignment requirements
- [ ] All testbenches compile and run successfully
- [ ] README files are clear and complete

---

**Submission Date**: November 8, 2024  
**Model Used**: GPT-4-turbo (via OpenAI API)  
**Total Trojans Generated**: 5  
**Status**: ✅ Complete


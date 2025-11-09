#!/usr/bin/env python3
"""
TROJAN2: Random Number Generator Bias Trojan Automation Script

This script generates trojan2 - Random Number Generator Bias Trojan.
This is the Python script version of trojan2_automation.ipynb
"""

import sys
import os
import shutil
from getpass import getpass

# Add parent directory to path (where opentitan_automation.py is)
current_dir = os.getcwd()
parent_dir = os.path.dirname(current_dir)
sys.path.insert(0, parent_dir)

# Import from the Python script
from opentitan_automation import OpenTitanHTGenerator

def main():
    """Main function for generating Trojan 2"""
    print("=" * 80)
    print("TROJAN2: Random Number Generator Bias Trojan")
    print("=" * 80)
    print()
    
    # Get API key from user input
    api_key = os.getenv("OPENAI_API_KEY") or os.getenv("ANTHROPIC_API_KEY")
    
    if not api_key:
        print("API key not found in environment variables.")
        print("Please enter your API key:")
        print("  - For OpenAI (GPT): starts with 'sk-'")
        print("  - For Anthropic (Claude): your API key")
        print()
        api_key = getpass("Enter API key (input will be hidden): ").strip()
        
        if not api_key:
            print("\n⚠️  ERROR: No API key provided!")
            print("   Please either:")
            print("   1. Set environment variable: export OPENAI_API_KEY=sk-your-key-here")
            print("   2. Run this script again and enter your API key")
            sys.exit(1)
        
        print("✅ API key received")
    else:
        print("✅ API key found in environment variable")
    
    # Initialize generator
    base_dir = os.path.dirname(os.getcwd())  # Parent directory
    opentitan_path = os.getenv("OPENTITAN_PATH") or os.path.join(os.path.dirname(base_dir), "opentitan")
    
    model_name = "gpt-4-turbo"  # Change to "gpt-4o", "gpt-4.1", "claude-3-opus-20240229", etc.
    
    generator = OpenTitanHTGenerator(
        api_key=api_key,
        model=model_name,
        log_dir=os.path.join(base_dir, "ai_logs"),
        opentitan_path=opentitan_path
    )
    
    print(f"\nModel: {generator.model}")
    print(f"API key set: {bool(api_key)}")
    print(f"API client initialized: {generator.client is not None}")
    print(f"OpenTitan path: {opentitan_path}")
    
    if generator.client is None:
        print("\n⚠️  WARNING: API client not initialized!")
        print("   Check:")
        print("   1. API key is correct (starts with 'sk-' for OpenAI)")
        print("   2. OpenAI package is installed: pip install openai")
        print("   3. Model name is correct (e.g., 'gpt-4-turbo', 'gpt-4o')")
        sys.exit(1)
    else:
        print("\n✅ Everything looks good! Ready to generate Trojans.")
    
    # Generate trojan2
    rtl_path = "hw/ip/csrng/rtl/csrng_core.sv"
    
    try:
        original_rtl = generator.read_rtl_file(rtl_path)
        print(f"\n✓ Read {len(original_rtl)} bytes from {rtl_path}")
    except FileNotFoundError as e:
        print(f"\n⚠ RTL file not found: {rtl_path}")
        print(f"  Please clone OpenTitan first: git clone https://github.com/lowRISC/opentitan.git")
        print(f"  Then set OPENTITAN_PATH environment variable.")
        sys.exit(1)
    
    # Generate Trojan
    print("Generating Trojan using LLM...")
    modified_rtl, log_file = generator.generate_trojan(
        "trojan2",
        original_rtl,
        """Insert a Trojan in the CSRNG (Cryptographically Secure Random Number Generator) that biases the output.
After receiving a specific trigger sequence (e.g., 0xDEADBEEF written to a control register), the RNG should produce predictable or biased outputs.
The RNG must still pass all original functional tests until triggered.""",
        """- Must detect trigger sequence
- Must bias output after trigger
- Original functionality must work until trigger""",
        """CSRNG is critical for key generation and cryptographic operations. Biased RNG compromises all security."""
    )
    
    print(f"✓ Generated Trojan (logged to {log_file})")
    
    # Save modified RTL
    output_dir = os.path.join(base_dir, "trojan2", "rtl")
    os.makedirs(output_dir, exist_ok=True)
    
    filename = os.path.basename(rtl_path).replace(".sv", ".v")
    output_file = os.path.join(output_dir, filename)
    
    with open(output_file, 'w') as f:
        f.write(modified_rtl)
    
    print(f"✓ Saved modified RTL to {output_file}")
    
    # Copy log to ai directory
    ai_dir = os.path.join(base_dir, "trojan2", "ai")
    os.makedirs(ai_dir, exist_ok=True)
    shutil.copy(log_file, os.path.join(ai_dir, os.path.basename(log_file)))
    
    print(f"✓ Copied AI log to {ai_dir}")
    
    print()
    print("=" * 80)
    print("Generation complete!")
    print("=" * 80)

if __name__ == "__main__":
    main()


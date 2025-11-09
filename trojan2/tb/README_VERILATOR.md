# Verilator vs Icarus Verilog for SystemVerilog Testbenches

## Issue with Verilator

Verilator is primarily a **synthesis tool**, not a full SystemVerilog simulator. It has limitations with:

1. **Timing delays** (`#5`, `#100`, etc.) - Verilator doesn't handle these well
2. **SystemVerilog testbenches** - Verilator is better for synthesizable RTL
3. **`forever` loops with delays** - The clock generation `forever #5 clk = ~clk;` doesn't work properly

## Solution: Use Icarus Verilog

For SystemVerilog testbenches with timing delays, **Icarus Verilog** is the better choice:

```bash
# Compile
iverilog -g2012 -o tb_csrng_bias_iv tb_csrng_bias.sv ../rtl/csrng_core.v

# Run
./tb_csrng_bias_iv
```

## Why Icarus Verilog?

- ✅ Full SystemVerilog support (with `-g2012` flag)
- ✅ Handles timing delays properly
- ✅ Supports `forever` loops with delays
- ✅ Better for testbenches
- ✅ Free and open source

## When to Use Verilator?

Verilator is better for:
- Synthesizable RTL verification
- Fast simulation of large designs
- C++ integration
- Performance-critical simulations

## When to Use Icarus Verilog?

Icarus Verilog is better for:
- SystemVerilog testbenches
- Timing-based simulations
- Learning and development
- Quick testbench verification

## Recommendation

**For this testbench, use Icarus Verilog:**

```bash
cd /Users/jochoi/github_repo/opentitan_trojans/trojan2/tb
iverilog -g2012 -o tb_csrng_bias_iv tb_csrng_bias.sv ../rtl/csrng_core.v
./tb_csrng_bias_iv
```


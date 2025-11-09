// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_csrng_bias__pch.h"

//============================================================
// Constructors

Vtb_csrng_bias::Vtb_csrng_bias(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_csrng_bias__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_csrng_bias::Vtb_csrng_bias(const char* _vcname__)
    : Vtb_csrng_bias(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_csrng_bias::~Vtb_csrng_bias() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_csrng_bias___024root___eval_debug_assertions(Vtb_csrng_bias___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_csrng_bias___024root___eval_static(Vtb_csrng_bias___024root* vlSelf);
void Vtb_csrng_bias___024root___eval_initial(Vtb_csrng_bias___024root* vlSelf);
void Vtb_csrng_bias___024root___eval_settle(Vtb_csrng_bias___024root* vlSelf);
void Vtb_csrng_bias___024root___eval(Vtb_csrng_bias___024root* vlSelf);

void Vtb_csrng_bias::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_csrng_bias::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_csrng_bias___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_csrng_bias___024root___eval_static(&(vlSymsp->TOP));
        Vtb_csrng_bias___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_csrng_bias___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_csrng_bias___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_csrng_bias::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vtb_csrng_bias::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_csrng_bias::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_csrng_bias___024root___eval_final(Vtb_csrng_bias___024root* vlSelf);

VL_ATTR_COLD void Vtb_csrng_bias::final() {
    Vtb_csrng_bias___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_csrng_bias::hierName() const { return vlSymsp->name(); }
const char* Vtb_csrng_bias::modelName() const { return "Vtb_csrng_bias"; }
unsigned Vtb_csrng_bias::threads() const { return 1; }
void Vtb_csrng_bias::prepareClone() const { contextp()->prepareClone(); }
void Vtb_csrng_bias::atClone() const {
    contextp()->threadPoolpOnClone();
}

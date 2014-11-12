//===-- NvfcInstPrinter.h - Convert Nvfc MCInst to assembly syntax ----===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This class prints a Nvfc MCInst to a .s file.
//
//===----------------------------------------------------------------------===//

#ifndef NvfcINSTPRINTER_H
#define NvfcINSTPRINTER_H

#include "llvm/MC/MCInstPrinter.h"

namespace llvm {
  class MCOperand;

  class NvfcInstPrinter : public MCInstPrinter {
  public:
    NvfcInstPrinter(const MCAsmInfo &MAI) : MCInstPrinter(MAI) {
    }

    virtual void printInst(const MCInst *MI, raw_ostream &O);

    // Autogenerated by tblgen.
    void printInstruction(const MCInst *MI, raw_ostream &O);
    static const char *getRegisterName(unsigned RegNo);

    void printOperand(const MCInst *MI, unsigned OpNo, raw_ostream &O,
                      const char *Modifier = 0);
    void printSExtOperand(const MCInst *MI, unsigned OpNo, raw_ostream &O,
			  const char *Modifier = 0);
    void printFlagsOperand(const MCInst *MI, unsigned OpNo, raw_ostream &O,
			  const char *Modifier = 0);
    void printPCRelImmOperand(const MCInst *MI, unsigned OpNo, raw_ostream &O);
    void printSrcMemOperand(const MCInst *MI, unsigned OpNo, raw_ostream &O,
                            const char *Modifier = 0);
    void printCCOperand(const MCInst *MI, unsigned OpNo, raw_ostream &O);

  };
}

#endif
#include "MainBlock.h"
#include "Block.h"
#include "BlockSlot.h"
#include "CodeBlocks.h"
#include <string>
#include <format>
#include <vector>

// for testing
#include <iostream>

MainBlock::MainBlock(){
  SlotStr = "{}";
  EndStr = "}%__ENDMAIN__%";
  this->ProgramStr = "main(){";
  this->SlotCount = 0;
  this->SlotList = LinkedList();
}

// *** TODO ***
bool MainBlock::insertBlock(Block droppedBlock){}
bool MainBlock::insertBlockBefore(Block droppedBlock, BlockSlot blockRef){}
bool MainBlock::insertBlockAfter(Block droppedBlock, BlockSlot blockRef){}

bool MainBlock::compileAndExecute(std::string* failMsgOut){
  // reset ProgramStr to initial str incase program is being recompiled
  this->ProgramStr = "main(){";
  // init empty string to contain inner body of main()'s code
  std::string bodyStr = "";
  std::vector<BlockSlot> slotArr = SlotList.getAsArray();
  
  // prevent OOB
  if(slotArr.size() != this->SlotCount){
    std::cerr << std::format("\nMAINBLOCK - slotArr.size() != SlotCount:\n\tslotArr.size()={}\n\tSlotCount={}\n", slotArr.size(), this->SlotCount);
    return "EXCEPTION"; 
  }
  
  // for each block
  for(int i=0; i<SlotCount; i++){
    // recursively build block in curr slot's contentStr & append to bodyStr 
    bodyStr += slotArr.at(i).getBlock().getContentStr();
  }

  // once ea of main's blocks contentStr added to bodyStr, append main's inner code body (i.e. bodyStr) to ProgramStr  
  this->ProgramStr += bodyStr;
  // now add closing '}' + program end marker str for the parser and ProgramStr now ready to be parsed
  this->ProgramStr += EndStr;

  /*
  TODO:
     
  */ 
}

std::string MainBlock::getProgramStr(){return this->ProgramStr;}


//std::string test = std::format("{}", "abb");
//for(int i=0; i<this->SlotCount; i++){}













#pragma once

#include "APPL_ParseBaseListener.h"


/*
  Still waiting on the list of terminal functions that will be available to call
  in order to manipulate the robot... Once that gets decided I will add rules into
  the parser for them so the appropriate calls to the robot interface can be made
  here whenever the interpreter encounters one within the tree and the rule's 
  enterStmt is called by the interpreter. Can't do much else to handle the logic 
  until I know how that logic needs to be handles and that will of course be based 
  on what exactly will be available as a terminal call...     
*/
class ApplListener : public APPL_ParseBaseListener{
  public:
    explicit ApplListener();

    // override rule handlers (must match base listener method names)
    // placeholder examples for now...
    // ---------------------------------------------------------------------------
    //virtual void enterMoveStmt(Type* ctx) override;
    //virtual void enterTurnStmt(Type* ctx) override;
    //virtual void enterWaitStmt(Type* ctx) override;
};

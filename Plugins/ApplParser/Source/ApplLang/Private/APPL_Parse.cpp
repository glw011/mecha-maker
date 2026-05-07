
// Generated from APPL_Parse.g4 by ANTLR 4.13.2
#include "ApplVisibility.h"
APPL_VISIBILITY_PUSH


#include "APPL_ParseListener.h"
#include "APPL_ParseVisitor.h"

#include "APPL_Parse.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct APPL_ParseStaticData final {
  APPL_ParseStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  APPL_ParseStaticData(const APPL_ParseStaticData&) = delete;
  APPL_ParseStaticData(APPL_ParseStaticData&&) = delete;
  APPL_ParseStaticData& operator=(const APPL_ParseStaticData&) = delete;
  APPL_ParseStaticData& operator=(APPL_ParseStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag appl_parseParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<APPL_ParseStaticData> appl_parseParserStaticData = nullptr;

void appl_parseParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (appl_parseParserStaticData != nullptr) {
    return;
  }
#else
  assert(appl_parseParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<APPL_ParseStaticData>(
    std::vector<std::string>{
      "main", "statement", "assign", "fun_def", "param_list", "conditional", 
      "if_else_stmt", "else_blk", "while_loop", "for_loop", "for_ea_loop", 
      "cblk", "return", "expr", "operatn", "unary_oprtn", "iteratn", "prefx_unary_oprtn", 
      "negatn", "binary_oprtn", "logic_or_expr", "logic_and_expr", "comparison_expr", 
      "add_expr", "mult_expr", "pow_expr", "augop", "factor", "fun_call", 
      "arg_list", "number", "pos_num", "neg_num", "booln"
    },
    std::vector<std::string>{
      "", "'$$__ENDMAIN__$$'", "'true'", "'false'", "'and'", "'or'", "'not'", 
      "'return'", "'if'", "'else'", "'switch'", "'case'", "'default'", "'def'", 
      "'continue'", "'break'", "'for'", "'each'", "'in'", "'while'", "'try'", 
      "'catch'", "'print'", "'**='", "'*='", "'//='", "'/='", "'+='", "'-='", 
      "'++'", "'--'", "','", "';'", "'.'", "'('", "')'", "'{'", "'}'", "'['", 
      "']'", "'**'", "'*'", "'//'", "'/'", "'%'", "'+'", "'-'", "'=='", 
      "'!='", "'!'", "'<='", "'<'", "'>='", "'>'", "'='", "'||'", "'&&'"
    },
    std::vector<std::string>{
      "", "KW_END", "KW_TRUE", "KW_FALSE", "KW_AND", "KW_OR", "KW_NOT", 
      "KW_RETURN", "KW_IF", "KW_ELSE", "KW_SWITCH", "KW_CASE", "KW_DFLT", 
      "KW_DEF", "KW_CONT", "KW_BREAK", "KW_FOR", "KW_EACH", "KW_IN", "KW_WHILE", 
      "KW_TRY", "KW_CATCH", "KW_PRINT", "POW_AUGOP", "MUL_AUGOP", "INTDIV_AUGOP", 
      "DIV_AUGOP", "INCR_AUGOP", "DECR_AUGOP", "INCR", "DECR", "COMMA", 
      "SC", "DOT", "LPAREN", "RPAREN", "LCRLYB", "RCRLYB", "LBRCKT", "RBRCKT", 
      "POW", "MUL", "INT_DIV", "DIV", "MOD", "ADD", "SUB", "EQUAL", "NOT_EQUAL", 
      "LGCL_NOT", "LTE", "LT", "GTE", "GT", "EQL", "LGCL_OR", "LGCL_AND", 
      "FLT", "INT", "ID", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,60,295,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,1,0,5,0,70,8,0,10,
  	0,12,0,73,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,
  	88,8,1,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,3,3,106,8,3,1,4,1,4,1,4,5,4,111,8,4,10,4,12,4,114,9,4,1,5,1,5,1,5,1,
  	5,3,5,120,8,5,1,6,1,6,1,6,1,6,1,6,1,6,3,6,128,8,6,1,7,1,7,1,7,1,7,3,7,
  	134,8,7,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,
  	9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,11,1,11,5,11,161,8,11,10,11,12,
  	11,164,9,11,1,11,1,11,1,12,1,12,1,12,3,12,171,8,12,1,13,1,13,3,13,175,
  	8,13,1,14,1,14,3,14,179,8,14,1,15,1,15,3,15,183,8,15,1,16,1,16,1,16,1,
  	16,1,16,1,16,3,16,191,8,16,1,17,1,17,1,17,1,17,1,17,3,17,198,8,17,1,18,
  	1,18,1,18,1,19,1,19,1,19,1,19,1,19,3,19,208,8,19,1,20,1,20,1,20,5,20,
  	213,8,20,10,20,12,20,216,9,20,1,21,1,21,1,21,5,21,221,8,21,10,21,12,21,
  	224,9,21,1,22,1,22,1,22,5,22,229,8,22,10,22,12,22,232,9,22,1,23,1,23,
  	1,23,5,23,237,8,23,10,23,12,23,240,9,23,1,24,1,24,1,24,5,24,245,8,24,
  	10,24,12,24,248,9,24,1,25,1,25,1,25,1,25,1,25,3,25,255,8,25,1,26,1,26,
  	1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,3,27,267,8,27,1,28,1,28,1,28,
  	3,28,272,8,28,1,28,1,28,1,29,1,29,1,29,5,29,279,8,29,10,29,12,29,282,
  	9,29,1,30,1,30,3,30,286,8,30,1,31,1,31,1,32,1,32,1,32,1,33,1,33,1,33,
  	0,0,34,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,
  	46,48,50,52,54,56,58,60,62,64,66,0,9,2,0,6,6,49,49,2,0,5,5,55,55,2,0,
  	4,4,56,56,2,0,47,48,50,53,1,0,45,46,1,0,41,44,1,0,24,28,1,0,57,58,1,0,
  	2,3,294,0,71,1,0,0,0,2,87,1,0,0,0,4,89,1,0,0,0,6,105,1,0,0,0,8,107,1,
  	0,0,0,10,119,1,0,0,0,12,121,1,0,0,0,14,133,1,0,0,0,16,135,1,0,0,0,18,
  	141,1,0,0,0,20,151,1,0,0,0,22,158,1,0,0,0,24,170,1,0,0,0,26,174,1,0,0,
  	0,28,178,1,0,0,0,30,182,1,0,0,0,32,190,1,0,0,0,34,197,1,0,0,0,36,199,
  	1,0,0,0,38,207,1,0,0,0,40,209,1,0,0,0,42,217,1,0,0,0,44,225,1,0,0,0,46,
  	233,1,0,0,0,48,241,1,0,0,0,50,254,1,0,0,0,52,256,1,0,0,0,54,266,1,0,0,
  	0,56,268,1,0,0,0,58,275,1,0,0,0,60,285,1,0,0,0,62,287,1,0,0,0,64,289,
  	1,0,0,0,66,292,1,0,0,0,68,70,3,2,1,0,69,68,1,0,0,0,70,73,1,0,0,0,71,69,
  	1,0,0,0,71,72,1,0,0,0,72,74,1,0,0,0,73,71,1,0,0,0,74,75,5,1,0,0,75,1,
  	1,0,0,0,76,77,3,4,2,0,77,78,5,32,0,0,78,88,1,0,0,0,79,88,3,6,3,0,80,88,
  	3,10,5,0,81,82,3,26,13,0,82,83,5,32,0,0,83,88,1,0,0,0,84,85,3,24,12,0,
  	85,86,5,32,0,0,86,88,1,0,0,0,87,76,1,0,0,0,87,79,1,0,0,0,87,80,1,0,0,
  	0,87,81,1,0,0,0,87,84,1,0,0,0,88,3,1,0,0,0,89,90,5,59,0,0,90,91,5,54,
  	0,0,91,92,3,26,13,0,92,5,1,0,0,0,93,94,5,13,0,0,94,95,5,59,0,0,95,96,
  	5,34,0,0,96,97,5,35,0,0,97,106,3,22,11,0,98,99,5,13,0,0,99,100,5,59,0,
  	0,100,101,5,34,0,0,101,102,3,8,4,0,102,103,5,35,0,0,103,104,3,22,11,0,
  	104,106,1,0,0,0,105,93,1,0,0,0,105,98,1,0,0,0,106,7,1,0,0,0,107,112,5,
  	59,0,0,108,109,5,31,0,0,109,111,5,59,0,0,110,108,1,0,0,0,111,114,1,0,
  	0,0,112,110,1,0,0,0,112,113,1,0,0,0,113,9,1,0,0,0,114,112,1,0,0,0,115,
  	120,3,12,6,0,116,120,3,16,8,0,117,120,3,18,9,0,118,120,3,20,10,0,119,
  	115,1,0,0,0,119,116,1,0,0,0,119,117,1,0,0,0,119,118,1,0,0,0,120,11,1,
  	0,0,0,121,122,5,8,0,0,122,123,5,34,0,0,123,124,3,26,13,0,124,125,5,35,
  	0,0,125,127,3,22,11,0,126,128,3,14,7,0,127,126,1,0,0,0,127,128,1,0,0,
  	0,128,13,1,0,0,0,129,130,5,9,0,0,130,134,3,12,6,0,131,132,5,9,0,0,132,
  	134,3,22,11,0,133,129,1,0,0,0,133,131,1,0,0,0,134,15,1,0,0,0,135,136,
  	5,19,0,0,136,137,5,34,0,0,137,138,3,26,13,0,138,139,5,35,0,0,139,140,
  	3,22,11,0,140,17,1,0,0,0,141,142,5,16,0,0,142,143,5,34,0,0,143,144,3,
  	4,2,0,144,145,5,32,0,0,145,146,3,26,13,0,146,147,5,32,0,0,147,148,3,28,
  	14,0,148,149,5,35,0,0,149,150,3,22,11,0,150,19,1,0,0,0,151,152,5,16,0,
  	0,152,153,5,17,0,0,153,154,5,59,0,0,154,155,5,18,0,0,155,156,5,59,0,0,
  	156,157,3,22,11,0,157,21,1,0,0,0,158,162,5,36,0,0,159,161,3,2,1,0,160,
  	159,1,0,0,0,161,164,1,0,0,0,162,160,1,0,0,0,162,163,1,0,0,0,163,165,1,
  	0,0,0,164,162,1,0,0,0,165,166,5,37,0,0,166,23,1,0,0,0,167,168,5,7,0,0,
  	168,171,3,26,13,0,169,171,5,7,0,0,170,167,1,0,0,0,170,169,1,0,0,0,171,
  	25,1,0,0,0,172,175,3,28,14,0,173,175,3,54,27,0,174,172,1,0,0,0,174,173,
  	1,0,0,0,175,27,1,0,0,0,176,179,3,30,15,0,177,179,3,38,19,0,178,176,1,
  	0,0,0,178,177,1,0,0,0,179,29,1,0,0,0,180,183,3,32,16,0,181,183,3,34,17,
  	0,182,180,1,0,0,0,182,181,1,0,0,0,183,31,1,0,0,0,184,185,3,54,27,0,185,
  	186,5,29,0,0,186,191,1,0,0,0,187,188,3,54,27,0,188,189,5,30,0,0,189,191,
  	1,0,0,0,190,184,1,0,0,0,190,187,1,0,0,0,191,33,1,0,0,0,192,198,3,36,18,
  	0,193,194,5,29,0,0,194,198,3,54,27,0,195,196,5,30,0,0,196,198,3,54,27,
  	0,197,192,1,0,0,0,197,193,1,0,0,0,197,195,1,0,0,0,198,35,1,0,0,0,199,
  	200,7,0,0,0,200,201,3,54,27,0,201,37,1,0,0,0,202,208,3,40,20,0,203,204,
  	3,54,27,0,204,205,3,52,26,0,205,206,3,26,13,0,206,208,1,0,0,0,207,202,
  	1,0,0,0,207,203,1,0,0,0,208,39,1,0,0,0,209,214,3,42,21,0,210,211,7,1,
  	0,0,211,213,3,42,21,0,212,210,1,0,0,0,213,216,1,0,0,0,214,212,1,0,0,0,
  	214,215,1,0,0,0,215,41,1,0,0,0,216,214,1,0,0,0,217,222,3,44,22,0,218,
  	219,7,2,0,0,219,221,3,44,22,0,220,218,1,0,0,0,221,224,1,0,0,0,222,220,
  	1,0,0,0,222,223,1,0,0,0,223,43,1,0,0,0,224,222,1,0,0,0,225,230,3,46,23,
  	0,226,227,7,3,0,0,227,229,3,46,23,0,228,226,1,0,0,0,229,232,1,0,0,0,230,
  	228,1,0,0,0,230,231,1,0,0,0,231,45,1,0,0,0,232,230,1,0,0,0,233,238,3,
  	48,24,0,234,235,7,4,0,0,235,237,3,48,24,0,236,234,1,0,0,0,237,240,1,0,
  	0,0,238,236,1,0,0,0,238,239,1,0,0,0,239,47,1,0,0,0,240,238,1,0,0,0,241,
  	246,3,50,25,0,242,243,7,5,0,0,243,245,3,50,25,0,244,242,1,0,0,0,245,248,
  	1,0,0,0,246,244,1,0,0,0,246,247,1,0,0,0,247,49,1,0,0,0,248,246,1,0,0,
  	0,249,255,3,54,27,0,250,251,3,54,27,0,251,252,5,40,0,0,252,253,3,50,25,
  	0,253,255,1,0,0,0,254,249,1,0,0,0,254,250,1,0,0,0,255,51,1,0,0,0,256,
  	257,7,6,0,0,257,53,1,0,0,0,258,259,5,34,0,0,259,260,3,26,13,0,260,261,
  	5,35,0,0,261,267,1,0,0,0,262,267,3,56,28,0,263,267,3,60,30,0,264,267,
  	3,66,33,0,265,267,5,59,0,0,266,258,1,0,0,0,266,262,1,0,0,0,266,263,1,
  	0,0,0,266,264,1,0,0,0,266,265,1,0,0,0,267,55,1,0,0,0,268,269,5,59,0,0,
  	269,271,5,34,0,0,270,272,3,58,29,0,271,270,1,0,0,0,271,272,1,0,0,0,272,
  	273,1,0,0,0,273,274,5,35,0,0,274,57,1,0,0,0,275,280,3,26,13,0,276,277,
  	5,31,0,0,277,279,3,26,13,0,278,276,1,0,0,0,279,282,1,0,0,0,280,278,1,
  	0,0,0,280,281,1,0,0,0,281,59,1,0,0,0,282,280,1,0,0,0,283,286,3,62,31,
  	0,284,286,3,64,32,0,285,283,1,0,0,0,285,284,1,0,0,0,286,61,1,0,0,0,287,
  	288,7,7,0,0,288,63,1,0,0,0,289,290,5,46,0,0,290,291,3,62,31,0,291,65,
  	1,0,0,0,292,293,7,8,0,0,293,67,1,0,0,0,25,71,87,105,112,119,127,133,162,
  	170,174,178,182,190,197,207,214,222,230,238,246,254,266,271,280,285
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  appl_parseParserStaticData = std::move(staticData);
}

}

APPL_Parse::APPL_Parse(TokenStream *input) : APPL_Parse(input, antlr4::atn::ParserATNSimulatorOptions()) {}

APPL_Parse::APPL_Parse(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  APPL_Parse::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *appl_parseParserStaticData->atn, appl_parseParserStaticData->decisionToDFA, appl_parseParserStaticData->sharedContextCache, options);
}

APPL_Parse::~APPL_Parse() {
  delete _interpreter;
}

const atn::ATN& APPL_Parse::getATN() const {
  return *appl_parseParserStaticData->atn;
}

std::string APPL_Parse::getGrammarFileName() const {
  return "APPL_Parse.g4";
}

const std::vector<std::string>& APPL_Parse::getRuleNames() const {
  return appl_parseParserStaticData->ruleNames;
}

const dfa::Vocabulary& APPL_Parse::getVocabulary() const {
  return appl_parseParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView APPL_Parse::getSerializedATN() const {
  return appl_parseParserStaticData->serializedATN;
}


//----------------- MainContext ------------------------------------------------------------------

APPL_Parse::MainContext::MainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* APPL_Parse::MainContext::KW_END() {
  return getToken(APPL_Parse::KW_END, 0);
}

std::vector<APPL_Parse::StatementContext *> APPL_Parse::MainContext::statement() {
  return getRuleContexts<APPL_Parse::StatementContext>();
}

APPL_Parse::StatementContext* APPL_Parse::MainContext::statement(size_t i) {
  return getRuleContext<APPL_Parse::StatementContext>(i);
}


size_t APPL_Parse::MainContext::getRuleIndex() const {
  return APPL_Parse::RuleMain;
}

void APPL_Parse::MainContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMain(this);
}

void APPL_Parse::MainContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMain(this);
}


std::any APPL_Parse::MainContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitMain(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::MainContext* APPL_Parse::main() {
  MainContext *_localctx = _tracker.createInstance<MainContext>(_ctx, getState());
  enterRule(_localctx, 0, APPL_Parse::RuleMain);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(71);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1009439654019670476) != 0)) {
      setState(68);
      statement();
      setState(73);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(74);
    match(APPL_Parse::KW_END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

APPL_Parse::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

APPL_Parse::AssignContext* APPL_Parse::StatementContext::assign() {
  return getRuleContext<APPL_Parse::AssignContext>(0);
}

tree::TerminalNode* APPL_Parse::StatementContext::SC() {
  return getToken(APPL_Parse::SC, 0);
}

APPL_Parse::Fun_defContext* APPL_Parse::StatementContext::fun_def() {
  return getRuleContext<APPL_Parse::Fun_defContext>(0);
}

APPL_Parse::ConditionalContext* APPL_Parse::StatementContext::conditional() {
  return getRuleContext<APPL_Parse::ConditionalContext>(0);
}

APPL_Parse::ExprContext* APPL_Parse::StatementContext::expr() {
  return getRuleContext<APPL_Parse::ExprContext>(0);
}

APPL_Parse::ReturnContext* APPL_Parse::StatementContext::return_() {
  return getRuleContext<APPL_Parse::ReturnContext>(0);
}


size_t APPL_Parse::StatementContext::getRuleIndex() const {
  return APPL_Parse::RuleStatement;
}

void APPL_Parse::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void APPL_Parse::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any APPL_Parse::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::StatementContext* APPL_Parse::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, APPL_Parse::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(87);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(76);
      assign();
      setState(77);
      match(APPL_Parse::SC);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(79);
      fun_def();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(80);
      conditional();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(81);
      expr();
      setState(82);
      match(APPL_Parse::SC);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(84);
      return_();
      setState(85);
      match(APPL_Parse::SC);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignContext ------------------------------------------------------------------

APPL_Parse::AssignContext::AssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* APPL_Parse::AssignContext::ID() {
  return getToken(APPL_Parse::ID, 0);
}

tree::TerminalNode* APPL_Parse::AssignContext::EQL() {
  return getToken(APPL_Parse::EQL, 0);
}

APPL_Parse::ExprContext* APPL_Parse::AssignContext::expr() {
  return getRuleContext<APPL_Parse::ExprContext>(0);
}


size_t APPL_Parse::AssignContext::getRuleIndex() const {
  return APPL_Parse::RuleAssign;
}

void APPL_Parse::AssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssign(this);
}

void APPL_Parse::AssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssign(this);
}


std::any APPL_Parse::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::AssignContext* APPL_Parse::assign() {
  AssignContext *_localctx = _tracker.createInstance<AssignContext>(_ctx, getState());
  enterRule(_localctx, 4, APPL_Parse::RuleAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(89);
    match(APPL_Parse::ID);
    setState(90);
    match(APPL_Parse::EQL);
    setState(91);
    expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Fun_defContext ------------------------------------------------------------------

APPL_Parse::Fun_defContext::Fun_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* APPL_Parse::Fun_defContext::KW_DEF() {
  return getToken(APPL_Parse::KW_DEF, 0);
}

tree::TerminalNode* APPL_Parse::Fun_defContext::ID() {
  return getToken(APPL_Parse::ID, 0);
}

tree::TerminalNode* APPL_Parse::Fun_defContext::LPAREN() {
  return getToken(APPL_Parse::LPAREN, 0);
}

tree::TerminalNode* APPL_Parse::Fun_defContext::RPAREN() {
  return getToken(APPL_Parse::RPAREN, 0);
}

APPL_Parse::CblkContext* APPL_Parse::Fun_defContext::cblk() {
  return getRuleContext<APPL_Parse::CblkContext>(0);
}

APPL_Parse::Param_listContext* APPL_Parse::Fun_defContext::param_list() {
  return getRuleContext<APPL_Parse::Param_listContext>(0);
}


size_t APPL_Parse::Fun_defContext::getRuleIndex() const {
  return APPL_Parse::RuleFun_def;
}

void APPL_Parse::Fun_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFun_def(this);
}

void APPL_Parse::Fun_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFun_def(this);
}


std::any APPL_Parse::Fun_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitFun_def(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::Fun_defContext* APPL_Parse::fun_def() {
  Fun_defContext *_localctx = _tracker.createInstance<Fun_defContext>(_ctx, getState());
  enterRule(_localctx, 6, APPL_Parse::RuleFun_def);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(105);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(93);
      match(APPL_Parse::KW_DEF);
      setState(94);
      match(APPL_Parse::ID);
      setState(95);
      match(APPL_Parse::LPAREN);
      setState(96);
      match(APPL_Parse::RPAREN);
      setState(97);
      cblk();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(98);
      match(APPL_Parse::KW_DEF);
      setState(99);
      match(APPL_Parse::ID);
      setState(100);
      match(APPL_Parse::LPAREN);
      setState(101);
      param_list();
      setState(102);
      match(APPL_Parse::RPAREN);
      setState(103);
      cblk();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Param_listContext ------------------------------------------------------------------

APPL_Parse::Param_listContext::Param_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> APPL_Parse::Param_listContext::ID() {
  return getTokens(APPL_Parse::ID);
}

tree::TerminalNode* APPL_Parse::Param_listContext::ID(size_t i) {
  return getToken(APPL_Parse::ID, i);
}

std::vector<tree::TerminalNode *> APPL_Parse::Param_listContext::COMMA() {
  return getTokens(APPL_Parse::COMMA);
}

tree::TerminalNode* APPL_Parse::Param_listContext::COMMA(size_t i) {
  return getToken(APPL_Parse::COMMA, i);
}


size_t APPL_Parse::Param_listContext::getRuleIndex() const {
  return APPL_Parse::RuleParam_list;
}

void APPL_Parse::Param_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParam_list(this);
}

void APPL_Parse::Param_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParam_list(this);
}


std::any APPL_Parse::Param_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitParam_list(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::Param_listContext* APPL_Parse::param_list() {
  Param_listContext *_localctx = _tracker.createInstance<Param_listContext>(_ctx, getState());
  enterRule(_localctx, 8, APPL_Parse::RuleParam_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(107);
    match(APPL_Parse::ID);
    setState(112);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == APPL_Parse::COMMA) {
      setState(108);
      match(APPL_Parse::COMMA);
      setState(109);
      match(APPL_Parse::ID);
      setState(114);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionalContext ------------------------------------------------------------------

APPL_Parse::ConditionalContext::ConditionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

APPL_Parse::If_else_stmtContext* APPL_Parse::ConditionalContext::if_else_stmt() {
  return getRuleContext<APPL_Parse::If_else_stmtContext>(0);
}

APPL_Parse::While_loopContext* APPL_Parse::ConditionalContext::while_loop() {
  return getRuleContext<APPL_Parse::While_loopContext>(0);
}

APPL_Parse::For_loopContext* APPL_Parse::ConditionalContext::for_loop() {
  return getRuleContext<APPL_Parse::For_loopContext>(0);
}

APPL_Parse::For_ea_loopContext* APPL_Parse::ConditionalContext::for_ea_loop() {
  return getRuleContext<APPL_Parse::For_ea_loopContext>(0);
}


size_t APPL_Parse::ConditionalContext::getRuleIndex() const {
  return APPL_Parse::RuleConditional;
}

void APPL_Parse::ConditionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditional(this);
}

void APPL_Parse::ConditionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditional(this);
}


std::any APPL_Parse::ConditionalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitConditional(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::ConditionalContext* APPL_Parse::conditional() {
  ConditionalContext *_localctx = _tracker.createInstance<ConditionalContext>(_ctx, getState());
  enterRule(_localctx, 10, APPL_Parse::RuleConditional);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(119);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(115);
      if_else_stmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(116);
      while_loop();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(117);
      for_loop();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(118);
      for_ea_loop();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_else_stmtContext ------------------------------------------------------------------

APPL_Parse::If_else_stmtContext::If_else_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* APPL_Parse::If_else_stmtContext::KW_IF() {
  return getToken(APPL_Parse::KW_IF, 0);
}

tree::TerminalNode* APPL_Parse::If_else_stmtContext::LPAREN() {
  return getToken(APPL_Parse::LPAREN, 0);
}

APPL_Parse::ExprContext* APPL_Parse::If_else_stmtContext::expr() {
  return getRuleContext<APPL_Parse::ExprContext>(0);
}

tree::TerminalNode* APPL_Parse::If_else_stmtContext::RPAREN() {
  return getToken(APPL_Parse::RPAREN, 0);
}

APPL_Parse::CblkContext* APPL_Parse::If_else_stmtContext::cblk() {
  return getRuleContext<APPL_Parse::CblkContext>(0);
}

APPL_Parse::Else_blkContext* APPL_Parse::If_else_stmtContext::else_blk() {
  return getRuleContext<APPL_Parse::Else_blkContext>(0);
}


size_t APPL_Parse::If_else_stmtContext::getRuleIndex() const {
  return APPL_Parse::RuleIf_else_stmt;
}

void APPL_Parse::If_else_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_else_stmt(this);
}

void APPL_Parse::If_else_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_else_stmt(this);
}


std::any APPL_Parse::If_else_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitIf_else_stmt(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::If_else_stmtContext* APPL_Parse::if_else_stmt() {
  If_else_stmtContext *_localctx = _tracker.createInstance<If_else_stmtContext>(_ctx, getState());
  enterRule(_localctx, 12, APPL_Parse::RuleIf_else_stmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(121);
    match(APPL_Parse::KW_IF);
    setState(122);
    match(APPL_Parse::LPAREN);
    setState(123);
    expr();
    setState(124);
    match(APPL_Parse::RPAREN);
    setState(125);
    cblk();
    setState(127);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == APPL_Parse::KW_ELSE) {
      setState(126);
      else_blk();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Else_blkContext ------------------------------------------------------------------

APPL_Parse::Else_blkContext::Else_blkContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* APPL_Parse::Else_blkContext::KW_ELSE() {
  return getToken(APPL_Parse::KW_ELSE, 0);
}

APPL_Parse::If_else_stmtContext* APPL_Parse::Else_blkContext::if_else_stmt() {
  return getRuleContext<APPL_Parse::If_else_stmtContext>(0);
}

APPL_Parse::CblkContext* APPL_Parse::Else_blkContext::cblk() {
  return getRuleContext<APPL_Parse::CblkContext>(0);
}


size_t APPL_Parse::Else_blkContext::getRuleIndex() const {
  return APPL_Parse::RuleElse_blk;
}

void APPL_Parse::Else_blkContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElse_blk(this);
}

void APPL_Parse::Else_blkContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElse_blk(this);
}


std::any APPL_Parse::Else_blkContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitElse_blk(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::Else_blkContext* APPL_Parse::else_blk() {
  Else_blkContext *_localctx = _tracker.createInstance<Else_blkContext>(_ctx, getState());
  enterRule(_localctx, 14, APPL_Parse::RuleElse_blk);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(133);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(129);
      match(APPL_Parse::KW_ELSE);
      setState(130);
      if_else_stmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(131);
      match(APPL_Parse::KW_ELSE);
      setState(132);
      cblk();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- While_loopContext ------------------------------------------------------------------

APPL_Parse::While_loopContext::While_loopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* APPL_Parse::While_loopContext::KW_WHILE() {
  return getToken(APPL_Parse::KW_WHILE, 0);
}

tree::TerminalNode* APPL_Parse::While_loopContext::LPAREN() {
  return getToken(APPL_Parse::LPAREN, 0);
}

APPL_Parse::ExprContext* APPL_Parse::While_loopContext::expr() {
  return getRuleContext<APPL_Parse::ExprContext>(0);
}

tree::TerminalNode* APPL_Parse::While_loopContext::RPAREN() {
  return getToken(APPL_Parse::RPAREN, 0);
}

APPL_Parse::CblkContext* APPL_Parse::While_loopContext::cblk() {
  return getRuleContext<APPL_Parse::CblkContext>(0);
}


size_t APPL_Parse::While_loopContext::getRuleIndex() const {
  return APPL_Parse::RuleWhile_loop;
}

void APPL_Parse::While_loopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhile_loop(this);
}

void APPL_Parse::While_loopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhile_loop(this);
}


std::any APPL_Parse::While_loopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitWhile_loop(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::While_loopContext* APPL_Parse::while_loop() {
  While_loopContext *_localctx = _tracker.createInstance<While_loopContext>(_ctx, getState());
  enterRule(_localctx, 16, APPL_Parse::RuleWhile_loop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(135);
    match(APPL_Parse::KW_WHILE);
    setState(136);
    match(APPL_Parse::LPAREN);
    setState(137);
    expr();
    setState(138);
    match(APPL_Parse::RPAREN);
    setState(139);
    cblk();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_loopContext ------------------------------------------------------------------

APPL_Parse::For_loopContext::For_loopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* APPL_Parse::For_loopContext::KW_FOR() {
  return getToken(APPL_Parse::KW_FOR, 0);
}

tree::TerminalNode* APPL_Parse::For_loopContext::LPAREN() {
  return getToken(APPL_Parse::LPAREN, 0);
}

APPL_Parse::AssignContext* APPL_Parse::For_loopContext::assign() {
  return getRuleContext<APPL_Parse::AssignContext>(0);
}

std::vector<tree::TerminalNode *> APPL_Parse::For_loopContext::SC() {
  return getTokens(APPL_Parse::SC);
}

tree::TerminalNode* APPL_Parse::For_loopContext::SC(size_t i) {
  return getToken(APPL_Parse::SC, i);
}

APPL_Parse::ExprContext* APPL_Parse::For_loopContext::expr() {
  return getRuleContext<APPL_Parse::ExprContext>(0);
}

APPL_Parse::OperatnContext* APPL_Parse::For_loopContext::operatn() {
  return getRuleContext<APPL_Parse::OperatnContext>(0);
}

tree::TerminalNode* APPL_Parse::For_loopContext::RPAREN() {
  return getToken(APPL_Parse::RPAREN, 0);
}

APPL_Parse::CblkContext* APPL_Parse::For_loopContext::cblk() {
  return getRuleContext<APPL_Parse::CblkContext>(0);
}


size_t APPL_Parse::For_loopContext::getRuleIndex() const {
  return APPL_Parse::RuleFor_loop;
}

void APPL_Parse::For_loopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFor_loop(this);
}

void APPL_Parse::For_loopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFor_loop(this);
}


std::any APPL_Parse::For_loopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitFor_loop(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::For_loopContext* APPL_Parse::for_loop() {
  For_loopContext *_localctx = _tracker.createInstance<For_loopContext>(_ctx, getState());
  enterRule(_localctx, 18, APPL_Parse::RuleFor_loop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(141);
    match(APPL_Parse::KW_FOR);
    setState(142);
    match(APPL_Parse::LPAREN);
    setState(143);
    assign();
    setState(144);
    match(APPL_Parse::SC);
    setState(145);
    expr();
    setState(146);
    match(APPL_Parse::SC);
    setState(147);
    operatn();
    setState(148);
    match(APPL_Parse::RPAREN);
    setState(149);
    cblk();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_ea_loopContext ------------------------------------------------------------------

APPL_Parse::For_ea_loopContext::For_ea_loopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* APPL_Parse::For_ea_loopContext::KW_FOR() {
  return getToken(APPL_Parse::KW_FOR, 0);
}

tree::TerminalNode* APPL_Parse::For_ea_loopContext::KW_EACH() {
  return getToken(APPL_Parse::KW_EACH, 0);
}

std::vector<tree::TerminalNode *> APPL_Parse::For_ea_loopContext::ID() {
  return getTokens(APPL_Parse::ID);
}

tree::TerminalNode* APPL_Parse::For_ea_loopContext::ID(size_t i) {
  return getToken(APPL_Parse::ID, i);
}

tree::TerminalNode* APPL_Parse::For_ea_loopContext::KW_IN() {
  return getToken(APPL_Parse::KW_IN, 0);
}

APPL_Parse::CblkContext* APPL_Parse::For_ea_loopContext::cblk() {
  return getRuleContext<APPL_Parse::CblkContext>(0);
}


size_t APPL_Parse::For_ea_loopContext::getRuleIndex() const {
  return APPL_Parse::RuleFor_ea_loop;
}

void APPL_Parse::For_ea_loopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFor_ea_loop(this);
}

void APPL_Parse::For_ea_loopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFor_ea_loop(this);
}


std::any APPL_Parse::For_ea_loopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitFor_ea_loop(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::For_ea_loopContext* APPL_Parse::for_ea_loop() {
  For_ea_loopContext *_localctx = _tracker.createInstance<For_ea_loopContext>(_ctx, getState());
  enterRule(_localctx, 20, APPL_Parse::RuleFor_ea_loop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(151);
    match(APPL_Parse::KW_FOR);
    setState(152);
    match(APPL_Parse::KW_EACH);
    setState(153);
    match(APPL_Parse::ID);
    setState(154);
    match(APPL_Parse::KW_IN);
    setState(155);
    match(APPL_Parse::ID);
    setState(156);
    cblk();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CblkContext ------------------------------------------------------------------

APPL_Parse::CblkContext::CblkContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* APPL_Parse::CblkContext::LCRLYB() {
  return getToken(APPL_Parse::LCRLYB, 0);
}

tree::TerminalNode* APPL_Parse::CblkContext::RCRLYB() {
  return getToken(APPL_Parse::RCRLYB, 0);
}

std::vector<APPL_Parse::StatementContext *> APPL_Parse::CblkContext::statement() {
  return getRuleContexts<APPL_Parse::StatementContext>();
}

APPL_Parse::StatementContext* APPL_Parse::CblkContext::statement(size_t i) {
  return getRuleContext<APPL_Parse::StatementContext>(i);
}


size_t APPL_Parse::CblkContext::getRuleIndex() const {
  return APPL_Parse::RuleCblk;
}

void APPL_Parse::CblkContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCblk(this);
}

void APPL_Parse::CblkContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCblk(this);
}


std::any APPL_Parse::CblkContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitCblk(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::CblkContext* APPL_Parse::cblk() {
  CblkContext *_localctx = _tracker.createInstance<CblkContext>(_ctx, getState());
  enterRule(_localctx, 22, APPL_Parse::RuleCblk);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(158);
    match(APPL_Parse::LCRLYB);
    setState(162);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1009439654019670476) != 0)) {
      setState(159);
      statement();
      setState(164);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(165);
    match(APPL_Parse::RCRLYB);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnContext ------------------------------------------------------------------

APPL_Parse::ReturnContext::ReturnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* APPL_Parse::ReturnContext::KW_RETURN() {
  return getToken(APPL_Parse::KW_RETURN, 0);
}

APPL_Parse::ExprContext* APPL_Parse::ReturnContext::expr() {
  return getRuleContext<APPL_Parse::ExprContext>(0);
}


size_t APPL_Parse::ReturnContext::getRuleIndex() const {
  return APPL_Parse::RuleReturn;
}

void APPL_Parse::ReturnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturn(this);
}

void APPL_Parse::ReturnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturn(this);
}


std::any APPL_Parse::ReturnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitReturn(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::ReturnContext* APPL_Parse::return_() {
  ReturnContext *_localctx = _tracker.createInstance<ReturnContext>(_ctx, getState());
  enterRule(_localctx, 24, APPL_Parse::RuleReturn);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(170);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(167);
      match(APPL_Parse::KW_RETURN);
      setState(168);
      expr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(169);
      match(APPL_Parse::KW_RETURN);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

APPL_Parse::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

APPL_Parse::OperatnContext* APPL_Parse::ExprContext::operatn() {
  return getRuleContext<APPL_Parse::OperatnContext>(0);
}

APPL_Parse::FactorContext* APPL_Parse::ExprContext::factor() {
  return getRuleContext<APPL_Parse::FactorContext>(0);
}


size_t APPL_Parse::ExprContext::getRuleIndex() const {
  return APPL_Parse::RuleExpr;
}

void APPL_Parse::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void APPL_Parse::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


std::any APPL_Parse::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::ExprContext* APPL_Parse::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 26, APPL_Parse::RuleExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(174);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(172);
      operatn();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(173);
      factor();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperatnContext ------------------------------------------------------------------

APPL_Parse::OperatnContext::OperatnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

APPL_Parse::Unary_oprtnContext* APPL_Parse::OperatnContext::unary_oprtn() {
  return getRuleContext<APPL_Parse::Unary_oprtnContext>(0);
}

APPL_Parse::Binary_oprtnContext* APPL_Parse::OperatnContext::binary_oprtn() {
  return getRuleContext<APPL_Parse::Binary_oprtnContext>(0);
}


size_t APPL_Parse::OperatnContext::getRuleIndex() const {
  return APPL_Parse::RuleOperatn;
}

void APPL_Parse::OperatnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperatn(this);
}

void APPL_Parse::OperatnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperatn(this);
}


std::any APPL_Parse::OperatnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitOperatn(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::OperatnContext* APPL_Parse::operatn() {
  OperatnContext *_localctx = _tracker.createInstance<OperatnContext>(_ctx, getState());
  enterRule(_localctx, 28, APPL_Parse::RuleOperatn);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(178);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(176);
      unary_oprtn();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(177);
      binary_oprtn();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unary_oprtnContext ------------------------------------------------------------------

APPL_Parse::Unary_oprtnContext::Unary_oprtnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

APPL_Parse::IteratnContext* APPL_Parse::Unary_oprtnContext::iteratn() {
  return getRuleContext<APPL_Parse::IteratnContext>(0);
}

APPL_Parse::Prefx_unary_oprtnContext* APPL_Parse::Unary_oprtnContext::prefx_unary_oprtn() {
  return getRuleContext<APPL_Parse::Prefx_unary_oprtnContext>(0);
}


size_t APPL_Parse::Unary_oprtnContext::getRuleIndex() const {
  return APPL_Parse::RuleUnary_oprtn;
}

void APPL_Parse::Unary_oprtnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_oprtn(this);
}

void APPL_Parse::Unary_oprtnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_oprtn(this);
}


std::any APPL_Parse::Unary_oprtnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitUnary_oprtn(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::Unary_oprtnContext* APPL_Parse::unary_oprtn() {
  Unary_oprtnContext *_localctx = _tracker.createInstance<Unary_oprtnContext>(_ctx, getState());
  enterRule(_localctx, 30, APPL_Parse::RuleUnary_oprtn);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(182);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case APPL_Parse::KW_TRUE:
      case APPL_Parse::KW_FALSE:
      case APPL_Parse::LPAREN:
      case APPL_Parse::SUB:
      case APPL_Parse::FLT:
      case APPL_Parse::INT:
      case APPL_Parse::ID: {
        enterOuterAlt(_localctx, 1);
        setState(180);
        iteratn();
        break;
      }

      case APPL_Parse::KW_NOT:
      case APPL_Parse::INCR:
      case APPL_Parse::DECR:
      case APPL_Parse::LGCL_NOT: {
        enterOuterAlt(_localctx, 2);
        setState(181);
        prefx_unary_oprtn();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IteratnContext ------------------------------------------------------------------

APPL_Parse::IteratnContext::IteratnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

APPL_Parse::FactorContext* APPL_Parse::IteratnContext::factor() {
  return getRuleContext<APPL_Parse::FactorContext>(0);
}

tree::TerminalNode* APPL_Parse::IteratnContext::INCR() {
  return getToken(APPL_Parse::INCR, 0);
}

tree::TerminalNode* APPL_Parse::IteratnContext::DECR() {
  return getToken(APPL_Parse::DECR, 0);
}


size_t APPL_Parse::IteratnContext::getRuleIndex() const {
  return APPL_Parse::RuleIteratn;
}

void APPL_Parse::IteratnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIteratn(this);
}

void APPL_Parse::IteratnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIteratn(this);
}


std::any APPL_Parse::IteratnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitIteratn(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::IteratnContext* APPL_Parse::iteratn() {
  IteratnContext *_localctx = _tracker.createInstance<IteratnContext>(_ctx, getState());
  enterRule(_localctx, 32, APPL_Parse::RuleIteratn);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(190);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(184);
      factor();
      setState(185);
      match(APPL_Parse::INCR);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(187);
      factor();
      setState(188);
      match(APPL_Parse::DECR);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Prefx_unary_oprtnContext ------------------------------------------------------------------

APPL_Parse::Prefx_unary_oprtnContext::Prefx_unary_oprtnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

APPL_Parse::NegatnContext* APPL_Parse::Prefx_unary_oprtnContext::negatn() {
  return getRuleContext<APPL_Parse::NegatnContext>(0);
}

tree::TerminalNode* APPL_Parse::Prefx_unary_oprtnContext::INCR() {
  return getToken(APPL_Parse::INCR, 0);
}

APPL_Parse::FactorContext* APPL_Parse::Prefx_unary_oprtnContext::factor() {
  return getRuleContext<APPL_Parse::FactorContext>(0);
}

tree::TerminalNode* APPL_Parse::Prefx_unary_oprtnContext::DECR() {
  return getToken(APPL_Parse::DECR, 0);
}


size_t APPL_Parse::Prefx_unary_oprtnContext::getRuleIndex() const {
  return APPL_Parse::RulePrefx_unary_oprtn;
}

void APPL_Parse::Prefx_unary_oprtnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrefx_unary_oprtn(this);
}

void APPL_Parse::Prefx_unary_oprtnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrefx_unary_oprtn(this);
}


std::any APPL_Parse::Prefx_unary_oprtnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitPrefx_unary_oprtn(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::Prefx_unary_oprtnContext* APPL_Parse::prefx_unary_oprtn() {
  Prefx_unary_oprtnContext *_localctx = _tracker.createInstance<Prefx_unary_oprtnContext>(_ctx, getState());
  enterRule(_localctx, 34, APPL_Parse::RulePrefx_unary_oprtn);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(197);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case APPL_Parse::KW_NOT:
      case APPL_Parse::LGCL_NOT: {
        enterOuterAlt(_localctx, 1);
        setState(192);
        negatn();
        break;
      }

      case APPL_Parse::INCR: {
        enterOuterAlt(_localctx, 2);
        setState(193);
        match(APPL_Parse::INCR);
        setState(194);
        factor();
        break;
      }

      case APPL_Parse::DECR: {
        enterOuterAlt(_localctx, 3);
        setState(195);
        match(APPL_Parse::DECR);
        setState(196);
        factor();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NegatnContext ------------------------------------------------------------------

APPL_Parse::NegatnContext::NegatnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

APPL_Parse::FactorContext* APPL_Parse::NegatnContext::factor() {
  return getRuleContext<APPL_Parse::FactorContext>(0);
}

tree::TerminalNode* APPL_Parse::NegatnContext::LGCL_NOT() {
  return getToken(APPL_Parse::LGCL_NOT, 0);
}

tree::TerminalNode* APPL_Parse::NegatnContext::KW_NOT() {
  return getToken(APPL_Parse::KW_NOT, 0);
}


size_t APPL_Parse::NegatnContext::getRuleIndex() const {
  return APPL_Parse::RuleNegatn;
}

void APPL_Parse::NegatnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNegatn(this);
}

void APPL_Parse::NegatnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNegatn(this);
}


std::any APPL_Parse::NegatnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitNegatn(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::NegatnContext* APPL_Parse::negatn() {
  NegatnContext *_localctx = _tracker.createInstance<NegatnContext>(_ctx, getState());
  enterRule(_localctx, 36, APPL_Parse::RuleNegatn);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(199);
    _la = _input->LA(1);
    if (!(_la == APPL_Parse::KW_NOT

    || _la == APPL_Parse::LGCL_NOT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(200);
    factor();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binary_oprtnContext ------------------------------------------------------------------

APPL_Parse::Binary_oprtnContext::Binary_oprtnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

APPL_Parse::Logic_or_exprContext* APPL_Parse::Binary_oprtnContext::logic_or_expr() {
  return getRuleContext<APPL_Parse::Logic_or_exprContext>(0);
}

APPL_Parse::FactorContext* APPL_Parse::Binary_oprtnContext::factor() {
  return getRuleContext<APPL_Parse::FactorContext>(0);
}

APPL_Parse::AugopContext* APPL_Parse::Binary_oprtnContext::augop() {
  return getRuleContext<APPL_Parse::AugopContext>(0);
}

APPL_Parse::ExprContext* APPL_Parse::Binary_oprtnContext::expr() {
  return getRuleContext<APPL_Parse::ExprContext>(0);
}


size_t APPL_Parse::Binary_oprtnContext::getRuleIndex() const {
  return APPL_Parse::RuleBinary_oprtn;
}

void APPL_Parse::Binary_oprtnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinary_oprtn(this);
}

void APPL_Parse::Binary_oprtnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinary_oprtn(this);
}


std::any APPL_Parse::Binary_oprtnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitBinary_oprtn(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::Binary_oprtnContext* APPL_Parse::binary_oprtn() {
  Binary_oprtnContext *_localctx = _tracker.createInstance<Binary_oprtnContext>(_ctx, getState());
  enterRule(_localctx, 38, APPL_Parse::RuleBinary_oprtn);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(207);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(202);
      logic_or_expr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(203);
      factor();
      setState(204);
      augop();
      setState(205);
      expr();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logic_or_exprContext ------------------------------------------------------------------

APPL_Parse::Logic_or_exprContext::Logic_or_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<APPL_Parse::Logic_and_exprContext *> APPL_Parse::Logic_or_exprContext::logic_and_expr() {
  return getRuleContexts<APPL_Parse::Logic_and_exprContext>();
}

APPL_Parse::Logic_and_exprContext* APPL_Parse::Logic_or_exprContext::logic_and_expr(size_t i) {
  return getRuleContext<APPL_Parse::Logic_and_exprContext>(i);
}

std::vector<tree::TerminalNode *> APPL_Parse::Logic_or_exprContext::KW_OR() {
  return getTokens(APPL_Parse::KW_OR);
}

tree::TerminalNode* APPL_Parse::Logic_or_exprContext::KW_OR(size_t i) {
  return getToken(APPL_Parse::KW_OR, i);
}

std::vector<tree::TerminalNode *> APPL_Parse::Logic_or_exprContext::LGCL_OR() {
  return getTokens(APPL_Parse::LGCL_OR);
}

tree::TerminalNode* APPL_Parse::Logic_or_exprContext::LGCL_OR(size_t i) {
  return getToken(APPL_Parse::LGCL_OR, i);
}


size_t APPL_Parse::Logic_or_exprContext::getRuleIndex() const {
  return APPL_Parse::RuleLogic_or_expr;
}

void APPL_Parse::Logic_or_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogic_or_expr(this);
}

void APPL_Parse::Logic_or_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogic_or_expr(this);
}


std::any APPL_Parse::Logic_or_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitLogic_or_expr(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::Logic_or_exprContext* APPL_Parse::logic_or_expr() {
  Logic_or_exprContext *_localctx = _tracker.createInstance<Logic_or_exprContext>(_ctx, getState());
  enterRule(_localctx, 40, APPL_Parse::RuleLogic_or_expr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(209);
    logic_and_expr();
    setState(214);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == APPL_Parse::KW_OR

    || _la == APPL_Parse::LGCL_OR) {
      setState(210);
      _la = _input->LA(1);
      if (!(_la == APPL_Parse::KW_OR

      || _la == APPL_Parse::LGCL_OR)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(211);
      logic_and_expr();
      setState(216);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logic_and_exprContext ------------------------------------------------------------------

APPL_Parse::Logic_and_exprContext::Logic_and_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<APPL_Parse::Comparison_exprContext *> APPL_Parse::Logic_and_exprContext::comparison_expr() {
  return getRuleContexts<APPL_Parse::Comparison_exprContext>();
}

APPL_Parse::Comparison_exprContext* APPL_Parse::Logic_and_exprContext::comparison_expr(size_t i) {
  return getRuleContext<APPL_Parse::Comparison_exprContext>(i);
}

std::vector<tree::TerminalNode *> APPL_Parse::Logic_and_exprContext::KW_AND() {
  return getTokens(APPL_Parse::KW_AND);
}

tree::TerminalNode* APPL_Parse::Logic_and_exprContext::KW_AND(size_t i) {
  return getToken(APPL_Parse::KW_AND, i);
}

std::vector<tree::TerminalNode *> APPL_Parse::Logic_and_exprContext::LGCL_AND() {
  return getTokens(APPL_Parse::LGCL_AND);
}

tree::TerminalNode* APPL_Parse::Logic_and_exprContext::LGCL_AND(size_t i) {
  return getToken(APPL_Parse::LGCL_AND, i);
}


size_t APPL_Parse::Logic_and_exprContext::getRuleIndex() const {
  return APPL_Parse::RuleLogic_and_expr;
}

void APPL_Parse::Logic_and_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogic_and_expr(this);
}

void APPL_Parse::Logic_and_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogic_and_expr(this);
}


std::any APPL_Parse::Logic_and_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitLogic_and_expr(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::Logic_and_exprContext* APPL_Parse::logic_and_expr() {
  Logic_and_exprContext *_localctx = _tracker.createInstance<Logic_and_exprContext>(_ctx, getState());
  enterRule(_localctx, 42, APPL_Parse::RuleLogic_and_expr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(217);
    comparison_expr();
    setState(222);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == APPL_Parse::KW_AND

    || _la == APPL_Parse::LGCL_AND) {
      setState(218);
      _la = _input->LA(1);
      if (!(_la == APPL_Parse::KW_AND

      || _la == APPL_Parse::LGCL_AND)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(219);
      comparison_expr();
      setState(224);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Comparison_exprContext ------------------------------------------------------------------

APPL_Parse::Comparison_exprContext::Comparison_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<APPL_Parse::Add_exprContext *> APPL_Parse::Comparison_exprContext::add_expr() {
  return getRuleContexts<APPL_Parse::Add_exprContext>();
}

APPL_Parse::Add_exprContext* APPL_Parse::Comparison_exprContext::add_expr(size_t i) {
  return getRuleContext<APPL_Parse::Add_exprContext>(i);
}

std::vector<tree::TerminalNode *> APPL_Parse::Comparison_exprContext::LT() {
  return getTokens(APPL_Parse::LT);
}

tree::TerminalNode* APPL_Parse::Comparison_exprContext::LT(size_t i) {
  return getToken(APPL_Parse::LT, i);
}

std::vector<tree::TerminalNode *> APPL_Parse::Comparison_exprContext::LTE() {
  return getTokens(APPL_Parse::LTE);
}

tree::TerminalNode* APPL_Parse::Comparison_exprContext::LTE(size_t i) {
  return getToken(APPL_Parse::LTE, i);
}

std::vector<tree::TerminalNode *> APPL_Parse::Comparison_exprContext::GT() {
  return getTokens(APPL_Parse::GT);
}

tree::TerminalNode* APPL_Parse::Comparison_exprContext::GT(size_t i) {
  return getToken(APPL_Parse::GT, i);
}

std::vector<tree::TerminalNode *> APPL_Parse::Comparison_exprContext::GTE() {
  return getTokens(APPL_Parse::GTE);
}

tree::TerminalNode* APPL_Parse::Comparison_exprContext::GTE(size_t i) {
  return getToken(APPL_Parse::GTE, i);
}

std::vector<tree::TerminalNode *> APPL_Parse::Comparison_exprContext::EQUAL() {
  return getTokens(APPL_Parse::EQUAL);
}

tree::TerminalNode* APPL_Parse::Comparison_exprContext::EQUAL(size_t i) {
  return getToken(APPL_Parse::EQUAL, i);
}

std::vector<tree::TerminalNode *> APPL_Parse::Comparison_exprContext::NOT_EQUAL() {
  return getTokens(APPL_Parse::NOT_EQUAL);
}

tree::TerminalNode* APPL_Parse::Comparison_exprContext::NOT_EQUAL(size_t i) {
  return getToken(APPL_Parse::NOT_EQUAL, i);
}


size_t APPL_Parse::Comparison_exprContext::getRuleIndex() const {
  return APPL_Parse::RuleComparison_expr;
}

void APPL_Parse::Comparison_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComparison_expr(this);
}

void APPL_Parse::Comparison_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComparison_expr(this);
}


std::any APPL_Parse::Comparison_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitComparison_expr(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::Comparison_exprContext* APPL_Parse::comparison_expr() {
  Comparison_exprContext *_localctx = _tracker.createInstance<Comparison_exprContext>(_ctx, getState());
  enterRule(_localctx, 44, APPL_Parse::RuleComparison_expr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(225);
    add_expr();
    setState(230);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 17310711067705344) != 0)) {
      setState(226);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 17310711067705344) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(227);
      add_expr();
      setState(232);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Add_exprContext ------------------------------------------------------------------

APPL_Parse::Add_exprContext::Add_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<APPL_Parse::Mult_exprContext *> APPL_Parse::Add_exprContext::mult_expr() {
  return getRuleContexts<APPL_Parse::Mult_exprContext>();
}

APPL_Parse::Mult_exprContext* APPL_Parse::Add_exprContext::mult_expr(size_t i) {
  return getRuleContext<APPL_Parse::Mult_exprContext>(i);
}

std::vector<tree::TerminalNode *> APPL_Parse::Add_exprContext::ADD() {
  return getTokens(APPL_Parse::ADD);
}

tree::TerminalNode* APPL_Parse::Add_exprContext::ADD(size_t i) {
  return getToken(APPL_Parse::ADD, i);
}

std::vector<tree::TerminalNode *> APPL_Parse::Add_exprContext::SUB() {
  return getTokens(APPL_Parse::SUB);
}

tree::TerminalNode* APPL_Parse::Add_exprContext::SUB(size_t i) {
  return getToken(APPL_Parse::SUB, i);
}


size_t APPL_Parse::Add_exprContext::getRuleIndex() const {
  return APPL_Parse::RuleAdd_expr;
}

void APPL_Parse::Add_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdd_expr(this);
}

void APPL_Parse::Add_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdd_expr(this);
}


std::any APPL_Parse::Add_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitAdd_expr(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::Add_exprContext* APPL_Parse::add_expr() {
  Add_exprContext *_localctx = _tracker.createInstance<Add_exprContext>(_ctx, getState());
  enterRule(_localctx, 46, APPL_Parse::RuleAdd_expr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(233);
    mult_expr();
    setState(238);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == APPL_Parse::ADD

    || _la == APPL_Parse::SUB) {
      setState(234);
      _la = _input->LA(1);
      if (!(_la == APPL_Parse::ADD

      || _la == APPL_Parse::SUB)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(235);
      mult_expr();
      setState(240);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Mult_exprContext ------------------------------------------------------------------

APPL_Parse::Mult_exprContext::Mult_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<APPL_Parse::Pow_exprContext *> APPL_Parse::Mult_exprContext::pow_expr() {
  return getRuleContexts<APPL_Parse::Pow_exprContext>();
}

APPL_Parse::Pow_exprContext* APPL_Parse::Mult_exprContext::pow_expr(size_t i) {
  return getRuleContext<APPL_Parse::Pow_exprContext>(i);
}

std::vector<tree::TerminalNode *> APPL_Parse::Mult_exprContext::MUL() {
  return getTokens(APPL_Parse::MUL);
}

tree::TerminalNode* APPL_Parse::Mult_exprContext::MUL(size_t i) {
  return getToken(APPL_Parse::MUL, i);
}

std::vector<tree::TerminalNode *> APPL_Parse::Mult_exprContext::DIV() {
  return getTokens(APPL_Parse::DIV);
}

tree::TerminalNode* APPL_Parse::Mult_exprContext::DIV(size_t i) {
  return getToken(APPL_Parse::DIV, i);
}

std::vector<tree::TerminalNode *> APPL_Parse::Mult_exprContext::INT_DIV() {
  return getTokens(APPL_Parse::INT_DIV);
}

tree::TerminalNode* APPL_Parse::Mult_exprContext::INT_DIV(size_t i) {
  return getToken(APPL_Parse::INT_DIV, i);
}

std::vector<tree::TerminalNode *> APPL_Parse::Mult_exprContext::MOD() {
  return getTokens(APPL_Parse::MOD);
}

tree::TerminalNode* APPL_Parse::Mult_exprContext::MOD(size_t i) {
  return getToken(APPL_Parse::MOD, i);
}


size_t APPL_Parse::Mult_exprContext::getRuleIndex() const {
  return APPL_Parse::RuleMult_expr;
}

void APPL_Parse::Mult_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMult_expr(this);
}

void APPL_Parse::Mult_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMult_expr(this);
}


std::any APPL_Parse::Mult_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitMult_expr(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::Mult_exprContext* APPL_Parse::mult_expr() {
  Mult_exprContext *_localctx = _tracker.createInstance<Mult_exprContext>(_ctx, getState());
  enterRule(_localctx, 48, APPL_Parse::RuleMult_expr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(241);
    pow_expr();
    setState(246);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 32985348833280) != 0)) {
      setState(242);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 32985348833280) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(243);
      pow_expr();
      setState(248);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Pow_exprContext ------------------------------------------------------------------

APPL_Parse::Pow_exprContext::Pow_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

APPL_Parse::FactorContext* APPL_Parse::Pow_exprContext::factor() {
  return getRuleContext<APPL_Parse::FactorContext>(0);
}

tree::TerminalNode* APPL_Parse::Pow_exprContext::POW() {
  return getToken(APPL_Parse::POW, 0);
}

APPL_Parse::Pow_exprContext* APPL_Parse::Pow_exprContext::pow_expr() {
  return getRuleContext<APPL_Parse::Pow_exprContext>(0);
}


size_t APPL_Parse::Pow_exprContext::getRuleIndex() const {
  return APPL_Parse::RulePow_expr;
}

void APPL_Parse::Pow_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPow_expr(this);
}

void APPL_Parse::Pow_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPow_expr(this);
}


std::any APPL_Parse::Pow_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitPow_expr(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::Pow_exprContext* APPL_Parse::pow_expr() {
  Pow_exprContext *_localctx = _tracker.createInstance<Pow_exprContext>(_ctx, getState());
  enterRule(_localctx, 50, APPL_Parse::RulePow_expr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(254);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(249);
      factor();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(250);
      factor();
      setState(251);
      match(APPL_Parse::POW);
      setState(252);
      pow_expr();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AugopContext ------------------------------------------------------------------

APPL_Parse::AugopContext::AugopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* APPL_Parse::AugopContext::MUL_AUGOP() {
  return getToken(APPL_Parse::MUL_AUGOP, 0);
}

tree::TerminalNode* APPL_Parse::AugopContext::INTDIV_AUGOP() {
  return getToken(APPL_Parse::INTDIV_AUGOP, 0);
}

tree::TerminalNode* APPL_Parse::AugopContext::DIV_AUGOP() {
  return getToken(APPL_Parse::DIV_AUGOP, 0);
}

tree::TerminalNode* APPL_Parse::AugopContext::INCR_AUGOP() {
  return getToken(APPL_Parse::INCR_AUGOP, 0);
}

tree::TerminalNode* APPL_Parse::AugopContext::DECR_AUGOP() {
  return getToken(APPL_Parse::DECR_AUGOP, 0);
}


size_t APPL_Parse::AugopContext::getRuleIndex() const {
  return APPL_Parse::RuleAugop;
}

void APPL_Parse::AugopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAugop(this);
}

void APPL_Parse::AugopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAugop(this);
}


std::any APPL_Parse::AugopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitAugop(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::AugopContext* APPL_Parse::augop() {
  AugopContext *_localctx = _tracker.createInstance<AugopContext>(_ctx, getState());
  enterRule(_localctx, 52, APPL_Parse::RuleAugop);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(256);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 520093696) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

APPL_Parse::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* APPL_Parse::FactorContext::LPAREN() {
  return getToken(APPL_Parse::LPAREN, 0);
}

APPL_Parse::ExprContext* APPL_Parse::FactorContext::expr() {
  return getRuleContext<APPL_Parse::ExprContext>(0);
}

tree::TerminalNode* APPL_Parse::FactorContext::RPAREN() {
  return getToken(APPL_Parse::RPAREN, 0);
}

APPL_Parse::Fun_callContext* APPL_Parse::FactorContext::fun_call() {
  return getRuleContext<APPL_Parse::Fun_callContext>(0);
}

APPL_Parse::NumberContext* APPL_Parse::FactorContext::number() {
  return getRuleContext<APPL_Parse::NumberContext>(0);
}

APPL_Parse::BoolnContext* APPL_Parse::FactorContext::booln() {
  return getRuleContext<APPL_Parse::BoolnContext>(0);
}

tree::TerminalNode* APPL_Parse::FactorContext::ID() {
  return getToken(APPL_Parse::ID, 0);
}


size_t APPL_Parse::FactorContext::getRuleIndex() const {
  return APPL_Parse::RuleFactor;
}

void APPL_Parse::FactorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor(this);
}

void APPL_Parse::FactorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor(this);
}


std::any APPL_Parse::FactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitFactor(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::FactorContext* APPL_Parse::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 54, APPL_Parse::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(266);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(258);
      match(APPL_Parse::LPAREN);
      setState(259);
      expr();
      setState(260);
      match(APPL_Parse::RPAREN);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(262);
      fun_call();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(263);
      number();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(264);
      booln();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(265);
      match(APPL_Parse::ID);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Fun_callContext ------------------------------------------------------------------

APPL_Parse::Fun_callContext::Fun_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* APPL_Parse::Fun_callContext::ID() {
  return getToken(APPL_Parse::ID, 0);
}

tree::TerminalNode* APPL_Parse::Fun_callContext::LPAREN() {
  return getToken(APPL_Parse::LPAREN, 0);
}

tree::TerminalNode* APPL_Parse::Fun_callContext::RPAREN() {
  return getToken(APPL_Parse::RPAREN, 0);
}

APPL_Parse::Arg_listContext* APPL_Parse::Fun_callContext::arg_list() {
  return getRuleContext<APPL_Parse::Arg_listContext>(0);
}


size_t APPL_Parse::Fun_callContext::getRuleIndex() const {
  return APPL_Parse::RuleFun_call;
}

void APPL_Parse::Fun_callContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFun_call(this);
}

void APPL_Parse::Fun_callContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFun_call(this);
}


std::any APPL_Parse::Fun_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitFun_call(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::Fun_callContext* APPL_Parse::fun_call() {
  Fun_callContext *_localctx = _tracker.createInstance<Fun_callContext>(_ctx, getState());
  enterRule(_localctx, 56, APPL_Parse::RuleFun_call);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(268);
    match(APPL_Parse::ID);
    setState(269);
    match(APPL_Parse::LPAREN);
    setState(271);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1009439654019072076) != 0)) {
      setState(270);
      arg_list();
    }
    setState(273);
    match(APPL_Parse::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Arg_listContext ------------------------------------------------------------------

APPL_Parse::Arg_listContext::Arg_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<APPL_Parse::ExprContext *> APPL_Parse::Arg_listContext::expr() {
  return getRuleContexts<APPL_Parse::ExprContext>();
}

APPL_Parse::ExprContext* APPL_Parse::Arg_listContext::expr(size_t i) {
  return getRuleContext<APPL_Parse::ExprContext>(i);
}

std::vector<tree::TerminalNode *> APPL_Parse::Arg_listContext::COMMA() {
  return getTokens(APPL_Parse::COMMA);
}

tree::TerminalNode* APPL_Parse::Arg_listContext::COMMA(size_t i) {
  return getToken(APPL_Parse::COMMA, i);
}


size_t APPL_Parse::Arg_listContext::getRuleIndex() const {
  return APPL_Parse::RuleArg_list;
}

void APPL_Parse::Arg_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArg_list(this);
}

void APPL_Parse::Arg_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArg_list(this);
}


std::any APPL_Parse::Arg_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitArg_list(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::Arg_listContext* APPL_Parse::arg_list() {
  Arg_listContext *_localctx = _tracker.createInstance<Arg_listContext>(_ctx, getState());
  enterRule(_localctx, 58, APPL_Parse::RuleArg_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(275);
    expr();
    setState(280);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == APPL_Parse::COMMA) {
      setState(276);
      match(APPL_Parse::COMMA);
      setState(277);
      expr();
      setState(282);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

APPL_Parse::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

APPL_Parse::Pos_numContext* APPL_Parse::NumberContext::pos_num() {
  return getRuleContext<APPL_Parse::Pos_numContext>(0);
}

APPL_Parse::Neg_numContext* APPL_Parse::NumberContext::neg_num() {
  return getRuleContext<APPL_Parse::Neg_numContext>(0);
}


size_t APPL_Parse::NumberContext::getRuleIndex() const {
  return APPL_Parse::RuleNumber;
}

void APPL_Parse::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}

void APPL_Parse::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}


std::any APPL_Parse::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::NumberContext* APPL_Parse::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 60, APPL_Parse::RuleNumber);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(285);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case APPL_Parse::FLT:
      case APPL_Parse::INT: {
        enterOuterAlt(_localctx, 1);
        setState(283);
        pos_num();
        break;
      }

      case APPL_Parse::SUB: {
        enterOuterAlt(_localctx, 2);
        setState(284);
        neg_num();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Pos_numContext ------------------------------------------------------------------

APPL_Parse::Pos_numContext::Pos_numContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* APPL_Parse::Pos_numContext::INT() {
  return getToken(APPL_Parse::INT, 0);
}

tree::TerminalNode* APPL_Parse::Pos_numContext::FLT() {
  return getToken(APPL_Parse::FLT, 0);
}


size_t APPL_Parse::Pos_numContext::getRuleIndex() const {
  return APPL_Parse::RulePos_num;
}

void APPL_Parse::Pos_numContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPos_num(this);
}

void APPL_Parse::Pos_numContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPos_num(this);
}


std::any APPL_Parse::Pos_numContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitPos_num(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::Pos_numContext* APPL_Parse::pos_num() {
  Pos_numContext *_localctx = _tracker.createInstance<Pos_numContext>(_ctx, getState());
  enterRule(_localctx, 62, APPL_Parse::RulePos_num);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(287);
    _la = _input->LA(1);
    if (!(_la == APPL_Parse::FLT

    || _la == APPL_Parse::INT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Neg_numContext ------------------------------------------------------------------

APPL_Parse::Neg_numContext::Neg_numContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* APPL_Parse::Neg_numContext::SUB() {
  return getToken(APPL_Parse::SUB, 0);
}

APPL_Parse::Pos_numContext* APPL_Parse::Neg_numContext::pos_num() {
  return getRuleContext<APPL_Parse::Pos_numContext>(0);
}


size_t APPL_Parse::Neg_numContext::getRuleIndex() const {
  return APPL_Parse::RuleNeg_num;
}

void APPL_Parse::Neg_numContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNeg_num(this);
}

void APPL_Parse::Neg_numContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNeg_num(this);
}


std::any APPL_Parse::Neg_numContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitNeg_num(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::Neg_numContext* APPL_Parse::neg_num() {
  Neg_numContext *_localctx = _tracker.createInstance<Neg_numContext>(_ctx, getState());
  enterRule(_localctx, 64, APPL_Parse::RuleNeg_num);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(289);
    match(APPL_Parse::SUB);
    setState(290);
    pos_num();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BoolnContext ------------------------------------------------------------------

APPL_Parse::BoolnContext::BoolnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* APPL_Parse::BoolnContext::KW_TRUE() {
  return getToken(APPL_Parse::KW_TRUE, 0);
}

tree::TerminalNode* APPL_Parse::BoolnContext::KW_FALSE() {
  return getToken(APPL_Parse::KW_FALSE, 0);
}


size_t APPL_Parse::BoolnContext::getRuleIndex() const {
  return APPL_Parse::RuleBooln;
}

void APPL_Parse::BoolnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooln(this);
}

void APPL_Parse::BoolnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooln(this);
}


std::any APPL_Parse::BoolnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<APPL_ParseVisitor*>(visitor))
    return parserVisitor->visitBooln(this);
  else
    return visitor->visitChildren(this);
}

APPL_Parse::BoolnContext* APPL_Parse::booln() {
  BoolnContext *_localctx = _tracker.createInstance<BoolnContext>(_ctx, getState());
  enterRule(_localctx, 66, APPL_Parse::RuleBooln);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(292);
    _la = _input->LA(1);
    if (!(_la == APPL_Parse::KW_TRUE

    || _la == APPL_Parse::KW_FALSE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void APPL_Parse::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  appl_parseParserInitialize();
#else
  ::antlr4::internal::call_once(appl_parseParserOnceFlag, appl_parseParserInitialize);
#endif
}

APPL_VISIBILITY_POP

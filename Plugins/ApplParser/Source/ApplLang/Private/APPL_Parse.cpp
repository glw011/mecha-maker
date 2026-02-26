#pragma GCC visibility push(default)

// Generated from APPL_Parse.g4 by ANTLR 4.13.2


#include "APPL_ParseListener.h"

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
      "negatn", "binary_oprtn", "arth_bin_op", "comparison", "aug_bin_op", 
      "augop", "factor", "fun_call", "arg_list", "number", "pos_num", "neg_num", 
      "booln"
    },
    std::vector<std::string>{
      "", "'true'", "'false'", "'and'", "'or'", "'not'", "'return'", "'if'", 
      "'else'", "'switch'", "'case'", "'default'", "'def'", "'continue'", 
      "'break'", "'for'", "'each'", "'in'", "'while'", "'try'", "'catch'", 
      "'print'", "'**='", "'*='", "'//='", "'/='", "'+='", "'-='", "'++'", 
      "'--'", "','", "';'", "'.'", "'('", "')'", "'{'", "'}'", "'['", "']'", 
      "'**'", "'*'", "'//'", "'/'", "'%'", "'+'", "'-'", "'=='", "'!='", 
      "'!'", "'<='", "'<'", "'>='", "'>'", "'='", "'||'", "'&&'"
    },
    std::vector<std::string>{
      "", "KW_TRUE", "KW_FALSE", "KW_AND", "KW_OR", "KW_NOT", "KW_RETURN", 
      "KW_IF", "KW_ELSE", "KW_SWITCH", "KW_CASE", "KW_DFLT", "KW_DEF", "KW_CONT", 
      "KW_BREAK", "KW_FOR", "KW_EACH", "KW_IN", "KW_WHILE", "KW_TRY", "KW_CATCH", 
      "KW_PRINT", "POW_AUGOP", "MUL_AUGOP", "INTDIV_AUGOP", "DIV_AUGOP", 
      "INCR_AUGOP", "DECR_AUGOP", "INCR", "DECR", "COMMA", "SC", "DOT", 
      "LPAREN", "RPAREN", "LCRLYB", "RCRLYB", "LBRCKT", "RBRCKT", "POW", 
      "MUL", "INT_DIV", "DIV", "MOD", "ADD", "SUB", "EQUAL", "NOT_EQUAL", 
      "LGCL_NOT", "LTE", "LT", "GTE", "GT", "EQL", "LGCL_OR", "LGCL_AND", 
      "FLT", "INT", "ID", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,59,301,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,1,0,5,0,64,8,0,10,0,12,0,67,9,0,1,0,1,0,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,82,8,1,1,2,1,2,1,2,1,2,1,3,
  	1,3,1,3,1,3,3,3,92,8,3,1,3,1,3,1,3,1,4,1,4,1,4,5,4,100,8,4,10,4,12,4,
  	103,9,4,1,5,1,5,1,5,1,5,3,5,109,8,5,1,6,1,6,1,6,1,6,1,6,1,6,3,6,117,8,
  	6,1,7,1,7,1,7,3,7,122,8,7,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,
  	1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,11,1,11,5,11,
  	149,8,11,10,11,12,11,152,9,11,1,11,1,11,1,12,1,12,1,12,3,12,159,8,12,
  	1,13,1,13,1,13,3,13,164,8,13,1,14,1,14,3,14,168,8,14,1,15,1,15,3,15,172,
  	8,15,1,16,1,16,1,16,1,17,1,17,1,17,3,17,180,8,17,1,18,1,18,1,18,1,19,
  	1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,3,19,196,8,19,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,3,20,
  	226,8,20,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,
  	1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,3,21,252,
  	8,21,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,3,22,262,8,22,1,23,1,23,
  	1,24,1,24,1,24,1,24,1,24,1,24,1,24,3,24,273,8,24,1,25,1,25,1,25,3,25,
  	278,8,25,1,25,1,25,1,26,1,26,1,26,5,26,285,8,26,10,26,12,26,288,9,26,
  	1,27,1,27,3,27,292,8,27,1,28,1,28,1,29,1,29,1,29,1,30,1,30,1,30,0,0,31,
  	0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,
  	50,52,54,56,58,60,0,7,1,0,28,29,2,0,5,5,48,48,2,0,4,4,54,54,2,0,3,3,55,
  	55,1,0,23,27,1,0,56,57,1,0,1,2,310,0,65,1,0,0,0,2,81,1,0,0,0,4,83,1,0,
  	0,0,6,87,1,0,0,0,8,96,1,0,0,0,10,108,1,0,0,0,12,110,1,0,0,0,14,118,1,
  	0,0,0,16,123,1,0,0,0,18,129,1,0,0,0,20,139,1,0,0,0,22,146,1,0,0,0,24,
  	158,1,0,0,0,26,163,1,0,0,0,28,167,1,0,0,0,30,171,1,0,0,0,32,173,1,0,0,
  	0,34,179,1,0,0,0,36,181,1,0,0,0,38,195,1,0,0,0,40,225,1,0,0,0,42,251,
  	1,0,0,0,44,261,1,0,0,0,46,263,1,0,0,0,48,272,1,0,0,0,50,274,1,0,0,0,52,
  	281,1,0,0,0,54,291,1,0,0,0,56,293,1,0,0,0,58,295,1,0,0,0,60,298,1,0,0,
  	0,62,64,3,2,1,0,63,62,1,0,0,0,64,67,1,0,0,0,65,63,1,0,0,0,65,66,1,0,0,
  	0,66,68,1,0,0,0,67,65,1,0,0,0,68,69,5,0,0,1,69,1,1,0,0,0,70,71,3,4,2,
  	0,71,72,5,31,0,0,72,82,1,0,0,0,73,82,3,6,3,0,74,82,3,10,5,0,75,76,3,26,
  	13,0,76,77,5,31,0,0,77,82,1,0,0,0,78,79,3,24,12,0,79,80,5,31,0,0,80,82,
  	1,0,0,0,81,70,1,0,0,0,81,73,1,0,0,0,81,74,1,0,0,0,81,75,1,0,0,0,81,78,
  	1,0,0,0,82,3,1,0,0,0,83,84,5,58,0,0,84,85,5,53,0,0,85,86,3,26,13,0,86,
  	5,1,0,0,0,87,88,5,12,0,0,88,89,5,58,0,0,89,91,5,33,0,0,90,92,3,8,4,0,
  	91,90,1,0,0,0,91,92,1,0,0,0,92,93,1,0,0,0,93,94,5,34,0,0,94,95,3,22,11,
  	0,95,7,1,0,0,0,96,101,5,58,0,0,97,98,5,30,0,0,98,100,5,58,0,0,99,97,1,
  	0,0,0,100,103,1,0,0,0,101,99,1,0,0,0,101,102,1,0,0,0,102,9,1,0,0,0,103,
  	101,1,0,0,0,104,109,3,12,6,0,105,109,3,16,8,0,106,109,3,18,9,0,107,109,
  	3,20,10,0,108,104,1,0,0,0,108,105,1,0,0,0,108,106,1,0,0,0,108,107,1,0,
  	0,0,109,11,1,0,0,0,110,111,5,7,0,0,111,112,5,33,0,0,112,113,3,26,13,0,
  	113,114,5,34,0,0,114,116,3,22,11,0,115,117,3,14,7,0,116,115,1,0,0,0,116,
  	117,1,0,0,0,117,13,1,0,0,0,118,121,5,8,0,0,119,122,3,12,6,0,120,122,3,
  	22,11,0,121,119,1,0,0,0,121,120,1,0,0,0,122,15,1,0,0,0,123,124,5,18,0,
  	0,124,125,5,33,0,0,125,126,3,26,13,0,126,127,5,34,0,0,127,128,3,22,11,
  	0,128,17,1,0,0,0,129,130,5,15,0,0,130,131,5,33,0,0,131,132,3,4,2,0,132,
  	133,5,31,0,0,133,134,3,26,13,0,134,135,5,31,0,0,135,136,3,32,16,0,136,
  	137,5,34,0,0,137,138,3,22,11,0,138,19,1,0,0,0,139,140,5,15,0,0,140,141,
  	5,16,0,0,141,142,5,58,0,0,142,143,5,17,0,0,143,144,5,58,0,0,144,145,3,
  	22,11,0,145,21,1,0,0,0,146,150,5,35,0,0,147,149,3,2,1,0,148,147,1,0,0,
  	0,149,152,1,0,0,0,150,148,1,0,0,0,150,151,1,0,0,0,151,153,1,0,0,0,152,
  	150,1,0,0,0,153,154,5,36,0,0,154,23,1,0,0,0,155,156,5,6,0,0,156,159,3,
  	26,13,0,157,159,5,6,0,0,158,155,1,0,0,0,158,157,1,0,0,0,159,25,1,0,0,
  	0,160,164,3,50,25,0,161,164,3,28,14,0,162,164,3,48,24,0,163,160,1,0,0,
  	0,163,161,1,0,0,0,163,162,1,0,0,0,164,27,1,0,0,0,165,168,3,30,15,0,166,
  	168,3,38,19,0,167,165,1,0,0,0,167,166,1,0,0,0,168,29,1,0,0,0,169,172,
  	3,32,16,0,170,172,3,34,17,0,171,169,1,0,0,0,171,170,1,0,0,0,172,31,1,
  	0,0,0,173,174,3,48,24,0,174,175,7,0,0,0,175,33,1,0,0,0,176,180,3,36,18,
  	0,177,178,7,0,0,0,178,180,3,48,24,0,179,176,1,0,0,0,179,177,1,0,0,0,180,
  	35,1,0,0,0,181,182,7,1,0,0,182,183,3,48,24,0,183,37,1,0,0,0,184,196,3,
  	40,20,0,185,196,3,42,21,0,186,187,3,48,24,0,187,188,7,2,0,0,188,189,3,
  	48,24,0,189,196,1,0,0,0,190,191,3,48,24,0,191,192,7,3,0,0,192,193,3,48,
  	24,0,193,196,1,0,0,0,194,196,3,44,22,0,195,184,1,0,0,0,195,185,1,0,0,
  	0,195,186,1,0,0,0,195,190,1,0,0,0,195,194,1,0,0,0,196,39,1,0,0,0,197,
  	198,3,48,24,0,198,199,5,39,0,0,199,200,3,48,24,0,200,226,1,0,0,0,201,
  	202,3,48,24,0,202,203,5,40,0,0,203,204,3,48,24,0,204,226,1,0,0,0,205,
  	206,3,48,24,0,206,207,5,42,0,0,207,208,3,48,24,0,208,226,1,0,0,0,209,
  	210,3,48,24,0,210,211,5,41,0,0,211,212,3,48,24,0,212,226,1,0,0,0,213,
  	214,3,48,24,0,214,215,5,43,0,0,215,216,3,48,24,0,216,226,1,0,0,0,217,
  	218,3,48,24,0,218,219,5,44,0,0,219,220,3,48,24,0,220,226,1,0,0,0,221,
  	222,3,48,24,0,222,223,5,45,0,0,223,224,3,48,24,0,224,226,1,0,0,0,225,
  	197,1,0,0,0,225,201,1,0,0,0,225,205,1,0,0,0,225,209,1,0,0,0,225,213,1,
  	0,0,0,225,217,1,0,0,0,225,221,1,0,0,0,226,41,1,0,0,0,227,228,3,48,24,
  	0,228,229,5,50,0,0,229,230,3,48,24,0,230,252,1,0,0,0,231,232,3,48,24,
  	0,232,233,5,49,0,0,233,234,3,48,24,0,234,252,1,0,0,0,235,236,3,48,24,
  	0,236,237,5,52,0,0,237,238,3,48,24,0,238,252,1,0,0,0,239,240,3,48,24,
  	0,240,241,5,51,0,0,241,242,3,48,24,0,242,252,1,0,0,0,243,244,3,48,24,
  	0,244,245,5,46,0,0,245,246,3,48,24,0,246,252,1,0,0,0,247,248,3,48,24,
  	0,248,249,5,47,0,0,249,250,3,48,24,0,250,252,1,0,0,0,251,227,1,0,0,0,
  	251,231,1,0,0,0,251,235,1,0,0,0,251,239,1,0,0,0,251,243,1,0,0,0,251,247,
  	1,0,0,0,252,43,1,0,0,0,253,254,3,48,24,0,254,255,5,22,0,0,255,256,3,48,
  	24,0,256,262,1,0,0,0,257,258,3,48,24,0,258,259,3,46,23,0,259,260,3,48,
  	24,0,260,262,1,0,0,0,261,253,1,0,0,0,261,257,1,0,0,0,262,45,1,0,0,0,263,
  	264,7,4,0,0,264,47,1,0,0,0,265,266,5,33,0,0,266,267,3,26,13,0,267,268,
  	5,34,0,0,268,273,1,0,0,0,269,273,3,54,27,0,270,273,3,60,30,0,271,273,
  	5,58,0,0,272,265,1,0,0,0,272,269,1,0,0,0,272,270,1,0,0,0,272,271,1,0,
  	0,0,273,49,1,0,0,0,274,275,5,58,0,0,275,277,5,33,0,0,276,278,3,52,26,
  	0,277,276,1,0,0,0,277,278,1,0,0,0,278,279,1,0,0,0,279,280,5,34,0,0,280,
  	51,1,0,0,0,281,286,3,26,13,0,282,283,5,30,0,0,283,285,3,26,13,0,284,282,
  	1,0,0,0,285,288,1,0,0,0,286,284,1,0,0,0,286,287,1,0,0,0,287,53,1,0,0,
  	0,288,286,1,0,0,0,289,292,3,56,28,0,290,292,3,58,29,0,291,289,1,0,0,0,
  	291,290,1,0,0,0,292,55,1,0,0,0,293,294,7,5,0,0,294,57,1,0,0,0,295,296,
  	5,45,0,0,296,297,3,56,28,0,297,59,1,0,0,0,298,299,7,6,0,0,299,61,1,0,
  	0,0,21,65,81,91,101,108,116,121,150,158,163,167,171,179,195,225,251,261,
  	272,277,286,291
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

tree::TerminalNode* APPL_Parse::MainContext::EOF() {
  return getToken(APPL_Parse::EOF, 0);
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
    setState(65);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 504719827009835238) != 0)) {
      setState(62);
      statement();
      setState(67);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(68);
    match(APPL_Parse::EOF);
   
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
    setState(81);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(70);
      assign();
      setState(71);
      match(APPL_Parse::SC);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(73);
      fun_def();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(74);
      conditional();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(75);
      expr();
      setState(76);
      match(APPL_Parse::SC);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(78);
      return_();
      setState(79);
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
    setState(83);
    match(APPL_Parse::ID);
    setState(84);
    match(APPL_Parse::EQL);
    setState(85);
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

APPL_Parse::Fun_defContext* APPL_Parse::fun_def() {
  Fun_defContext *_localctx = _tracker.createInstance<Fun_defContext>(_ctx, getState());
  enterRule(_localctx, 6, APPL_Parse::RuleFun_def);
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
    setState(87);
    match(APPL_Parse::KW_DEF);
    setState(88);
    match(APPL_Parse::ID);
    setState(89);
    match(APPL_Parse::LPAREN);
    setState(91);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == APPL_Parse::ID) {
      setState(90);
      param_list();
    }
    setState(93);
    match(APPL_Parse::RPAREN);
    setState(94);
    cblk();
   
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
    setState(96);
    match(APPL_Parse::ID);
    setState(101);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == APPL_Parse::COMMA) {
      setState(97);
      match(APPL_Parse::COMMA);
      setState(98);
      match(APPL_Parse::ID);
      setState(103);
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
    setState(108);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(104);
      if_else_stmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(105);
      while_loop();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(106);
      for_loop();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(107);
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
    setState(110);
    match(APPL_Parse::KW_IF);
    setState(111);
    match(APPL_Parse::LPAREN);
    setState(112);
    expr();
    setState(113);
    match(APPL_Parse::RPAREN);
    setState(114);
    cblk();
    setState(116);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == APPL_Parse::KW_ELSE) {
      setState(115);
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
    enterOuterAlt(_localctx, 1);
    setState(118);
    match(APPL_Parse::KW_ELSE);
    setState(121);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case APPL_Parse::KW_IF: {
        setState(119);
        if_else_stmt();
        break;
      }

      case APPL_Parse::LCRLYB: {
        setState(120);
        cblk();
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
    setState(123);
    match(APPL_Parse::KW_WHILE);
    setState(124);
    match(APPL_Parse::LPAREN);
    setState(125);
    expr();
    setState(126);
    match(APPL_Parse::RPAREN);
    setState(127);
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

APPL_Parse::IteratnContext* APPL_Parse::For_loopContext::iteratn() {
  return getRuleContext<APPL_Parse::IteratnContext>(0);
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
    setState(129);
    match(APPL_Parse::KW_FOR);
    setState(130);
    match(APPL_Parse::LPAREN);
    setState(131);
    assign();
    setState(132);
    match(APPL_Parse::SC);
    setState(133);
    expr();
    setState(134);
    match(APPL_Parse::SC);
    setState(135);
    iteratn();
    setState(136);
    match(APPL_Parse::RPAREN);
    setState(137);
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
    setState(139);
    match(APPL_Parse::KW_FOR);
    setState(140);
    match(APPL_Parse::KW_EACH);
    setState(141);
    match(APPL_Parse::ID);
    setState(142);
    match(APPL_Parse::KW_IN);
    setState(143);
    match(APPL_Parse::ID);
    setState(144);
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
    setState(146);
    match(APPL_Parse::LCRLYB);
    setState(150);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 504719827009835238) != 0)) {
      setState(147);
      statement();
      setState(152);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(153);
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
    setState(158);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(155);
      match(APPL_Parse::KW_RETURN);
      setState(156);
      expr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(157);
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

APPL_Parse::Fun_callContext* APPL_Parse::ExprContext::fun_call() {
  return getRuleContext<APPL_Parse::Fun_callContext>(0);
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
    setState(163);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(160);
      fun_call();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(161);
      operatn();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(162);
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
    setState(167);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(165);
      unary_oprtn();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(166);
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
    setState(171);
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
        setState(169);
        iteratn();
        break;
      }

      case APPL_Parse::KW_NOT:
      case APPL_Parse::INCR:
      case APPL_Parse::DECR:
      case APPL_Parse::LGCL_NOT: {
        enterOuterAlt(_localctx, 2);
        setState(170);
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

APPL_Parse::IteratnContext* APPL_Parse::iteratn() {
  IteratnContext *_localctx = _tracker.createInstance<IteratnContext>(_ctx, getState());
  enterRule(_localctx, 32, APPL_Parse::RuleIteratn);
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
    setState(173);
    factor();
    setState(174);
    _la = _input->LA(1);
    if (!(_la == APPL_Parse::INCR

    || _la == APPL_Parse::DECR)) {
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

//----------------- Prefx_unary_oprtnContext ------------------------------------------------------------------

APPL_Parse::Prefx_unary_oprtnContext::Prefx_unary_oprtnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

APPL_Parse::NegatnContext* APPL_Parse::Prefx_unary_oprtnContext::negatn() {
  return getRuleContext<APPL_Parse::NegatnContext>(0);
}

APPL_Parse::FactorContext* APPL_Parse::Prefx_unary_oprtnContext::factor() {
  return getRuleContext<APPL_Parse::FactorContext>(0);
}

tree::TerminalNode* APPL_Parse::Prefx_unary_oprtnContext::INCR() {
  return getToken(APPL_Parse::INCR, 0);
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

APPL_Parse::Prefx_unary_oprtnContext* APPL_Parse::prefx_unary_oprtn() {
  Prefx_unary_oprtnContext *_localctx = _tracker.createInstance<Prefx_unary_oprtnContext>(_ctx, getState());
  enterRule(_localctx, 34, APPL_Parse::RulePrefx_unary_oprtn);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(179);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case APPL_Parse::KW_NOT:
      case APPL_Parse::LGCL_NOT: {
        enterOuterAlt(_localctx, 1);
        setState(176);
        negatn();
        break;
      }

      case APPL_Parse::INCR:
      case APPL_Parse::DECR: {
        enterOuterAlt(_localctx, 2);
        setState(177);
        _la = _input->LA(1);
        if (!(_la == APPL_Parse::INCR

        || _la == APPL_Parse::DECR)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(178);
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
    setState(181);
    _la = _input->LA(1);
    if (!(_la == APPL_Parse::KW_NOT

    || _la == APPL_Parse::LGCL_NOT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(182);
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

APPL_Parse::Arth_bin_opContext* APPL_Parse::Binary_oprtnContext::arth_bin_op() {
  return getRuleContext<APPL_Parse::Arth_bin_opContext>(0);
}

APPL_Parse::ComparisonContext* APPL_Parse::Binary_oprtnContext::comparison() {
  return getRuleContext<APPL_Parse::ComparisonContext>(0);
}

std::vector<APPL_Parse::FactorContext *> APPL_Parse::Binary_oprtnContext::factor() {
  return getRuleContexts<APPL_Parse::FactorContext>();
}

APPL_Parse::FactorContext* APPL_Parse::Binary_oprtnContext::factor(size_t i) {
  return getRuleContext<APPL_Parse::FactorContext>(i);
}

tree::TerminalNode* APPL_Parse::Binary_oprtnContext::KW_OR() {
  return getToken(APPL_Parse::KW_OR, 0);
}

tree::TerminalNode* APPL_Parse::Binary_oprtnContext::LGCL_OR() {
  return getToken(APPL_Parse::LGCL_OR, 0);
}

tree::TerminalNode* APPL_Parse::Binary_oprtnContext::KW_AND() {
  return getToken(APPL_Parse::KW_AND, 0);
}

tree::TerminalNode* APPL_Parse::Binary_oprtnContext::LGCL_AND() {
  return getToken(APPL_Parse::LGCL_AND, 0);
}

APPL_Parse::Aug_bin_opContext* APPL_Parse::Binary_oprtnContext::aug_bin_op() {
  return getRuleContext<APPL_Parse::Aug_bin_opContext>(0);
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

APPL_Parse::Binary_oprtnContext* APPL_Parse::binary_oprtn() {
  Binary_oprtnContext *_localctx = _tracker.createInstance<Binary_oprtnContext>(_ctx, getState());
  enterRule(_localctx, 38, APPL_Parse::RuleBinary_oprtn);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(195);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(184);
      arth_bin_op();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(185);
      comparison();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(186);
      factor();
      setState(187);
      _la = _input->LA(1);
      if (!(_la == APPL_Parse::KW_OR

      || _la == APPL_Parse::LGCL_OR)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(188);
      factor();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(190);
      factor();
      setState(191);
      _la = _input->LA(1);
      if (!(_la == APPL_Parse::KW_AND

      || _la == APPL_Parse::LGCL_AND)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(192);
      factor();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(194);
      aug_bin_op();
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

//----------------- Arth_bin_opContext ------------------------------------------------------------------

APPL_Parse::Arth_bin_opContext::Arth_bin_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<APPL_Parse::FactorContext *> APPL_Parse::Arth_bin_opContext::factor() {
  return getRuleContexts<APPL_Parse::FactorContext>();
}

APPL_Parse::FactorContext* APPL_Parse::Arth_bin_opContext::factor(size_t i) {
  return getRuleContext<APPL_Parse::FactorContext>(i);
}

tree::TerminalNode* APPL_Parse::Arth_bin_opContext::POW() {
  return getToken(APPL_Parse::POW, 0);
}

tree::TerminalNode* APPL_Parse::Arth_bin_opContext::MUL() {
  return getToken(APPL_Parse::MUL, 0);
}

tree::TerminalNode* APPL_Parse::Arth_bin_opContext::DIV() {
  return getToken(APPL_Parse::DIV, 0);
}

tree::TerminalNode* APPL_Parse::Arth_bin_opContext::INT_DIV() {
  return getToken(APPL_Parse::INT_DIV, 0);
}

tree::TerminalNode* APPL_Parse::Arth_bin_opContext::MOD() {
  return getToken(APPL_Parse::MOD, 0);
}

tree::TerminalNode* APPL_Parse::Arth_bin_opContext::ADD() {
  return getToken(APPL_Parse::ADD, 0);
}

tree::TerminalNode* APPL_Parse::Arth_bin_opContext::SUB() {
  return getToken(APPL_Parse::SUB, 0);
}


size_t APPL_Parse::Arth_bin_opContext::getRuleIndex() const {
  return APPL_Parse::RuleArth_bin_op;
}

void APPL_Parse::Arth_bin_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArth_bin_op(this);
}

void APPL_Parse::Arth_bin_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArth_bin_op(this);
}

APPL_Parse::Arth_bin_opContext* APPL_Parse::arth_bin_op() {
  Arth_bin_opContext *_localctx = _tracker.createInstance<Arth_bin_opContext>(_ctx, getState());
  enterRule(_localctx, 40, APPL_Parse::RuleArth_bin_op);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(225);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(197);
      factor();
      setState(198);
      match(APPL_Parse::POW);
      setState(199);
      factor();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(201);
      factor();
      setState(202);
      match(APPL_Parse::MUL);
      setState(203);
      factor();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(205);
      factor();
      setState(206);
      match(APPL_Parse::DIV);
      setState(207);
      factor();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(209);
      factor();
      setState(210);
      match(APPL_Parse::INT_DIV);
      setState(211);
      factor();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(213);
      factor();
      setState(214);
      match(APPL_Parse::MOD);
      setState(215);
      factor();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(217);
      factor();
      setState(218);
      match(APPL_Parse::ADD);
      setState(219);
      factor();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(221);
      factor();
      setState(222);
      match(APPL_Parse::SUB);
      setState(223);
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

//----------------- ComparisonContext ------------------------------------------------------------------

APPL_Parse::ComparisonContext::ComparisonContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<APPL_Parse::FactorContext *> APPL_Parse::ComparisonContext::factor() {
  return getRuleContexts<APPL_Parse::FactorContext>();
}

APPL_Parse::FactorContext* APPL_Parse::ComparisonContext::factor(size_t i) {
  return getRuleContext<APPL_Parse::FactorContext>(i);
}

tree::TerminalNode* APPL_Parse::ComparisonContext::LT() {
  return getToken(APPL_Parse::LT, 0);
}

tree::TerminalNode* APPL_Parse::ComparisonContext::LTE() {
  return getToken(APPL_Parse::LTE, 0);
}

tree::TerminalNode* APPL_Parse::ComparisonContext::GT() {
  return getToken(APPL_Parse::GT, 0);
}

tree::TerminalNode* APPL_Parse::ComparisonContext::GTE() {
  return getToken(APPL_Parse::GTE, 0);
}

tree::TerminalNode* APPL_Parse::ComparisonContext::EQUAL() {
  return getToken(APPL_Parse::EQUAL, 0);
}

tree::TerminalNode* APPL_Parse::ComparisonContext::NOT_EQUAL() {
  return getToken(APPL_Parse::NOT_EQUAL, 0);
}


size_t APPL_Parse::ComparisonContext::getRuleIndex() const {
  return APPL_Parse::RuleComparison;
}

void APPL_Parse::ComparisonContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComparison(this);
}

void APPL_Parse::ComparisonContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComparison(this);
}

APPL_Parse::ComparisonContext* APPL_Parse::comparison() {
  ComparisonContext *_localctx = _tracker.createInstance<ComparisonContext>(_ctx, getState());
  enterRule(_localctx, 42, APPL_Parse::RuleComparison);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(251);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(227);
      factor();
      setState(228);
      match(APPL_Parse::LT);
      setState(229);
      factor();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(231);
      factor();
      setState(232);
      match(APPL_Parse::LTE);
      setState(233);
      factor();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(235);
      factor();
      setState(236);
      match(APPL_Parse::GT);
      setState(237);
      factor();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(239);
      factor();
      setState(240);
      match(APPL_Parse::GTE);
      setState(241);
      factor();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(243);
      factor();
      setState(244);
      match(APPL_Parse::EQUAL);
      setState(245);
      factor();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(247);
      factor();
      setState(248);
      match(APPL_Parse::NOT_EQUAL);
      setState(249);
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

//----------------- Aug_bin_opContext ------------------------------------------------------------------

APPL_Parse::Aug_bin_opContext::Aug_bin_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<APPL_Parse::FactorContext *> APPL_Parse::Aug_bin_opContext::factor() {
  return getRuleContexts<APPL_Parse::FactorContext>();
}

APPL_Parse::FactorContext* APPL_Parse::Aug_bin_opContext::factor(size_t i) {
  return getRuleContext<APPL_Parse::FactorContext>(i);
}

tree::TerminalNode* APPL_Parse::Aug_bin_opContext::POW_AUGOP() {
  return getToken(APPL_Parse::POW_AUGOP, 0);
}

APPL_Parse::AugopContext* APPL_Parse::Aug_bin_opContext::augop() {
  return getRuleContext<APPL_Parse::AugopContext>(0);
}


size_t APPL_Parse::Aug_bin_opContext::getRuleIndex() const {
  return APPL_Parse::RuleAug_bin_op;
}

void APPL_Parse::Aug_bin_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAug_bin_op(this);
}

void APPL_Parse::Aug_bin_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<APPL_ParseListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAug_bin_op(this);
}

APPL_Parse::Aug_bin_opContext* APPL_Parse::aug_bin_op() {
  Aug_bin_opContext *_localctx = _tracker.createInstance<Aug_bin_opContext>(_ctx, getState());
  enterRule(_localctx, 44, APPL_Parse::RuleAug_bin_op);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(261);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(253);
      factor();
      setState(254);
      match(APPL_Parse::POW_AUGOP);
      setState(255);
      factor();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(257);
      factor();
      setState(258);
      augop();
      setState(259);
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

APPL_Parse::AugopContext* APPL_Parse::augop() {
  AugopContext *_localctx = _tracker.createInstance<AugopContext>(_ctx, getState());
  enterRule(_localctx, 46, APPL_Parse::RuleAugop);
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
    setState(263);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 260046848) != 0))) {
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

APPL_Parse::FactorContext* APPL_Parse::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 48, APPL_Parse::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(272);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case APPL_Parse::LPAREN: {
        enterOuterAlt(_localctx, 1);
        setState(265);
        match(APPL_Parse::LPAREN);
        setState(266);
        expr();
        setState(267);
        match(APPL_Parse::RPAREN);
        break;
      }

      case APPL_Parse::SUB:
      case APPL_Parse::FLT:
      case APPL_Parse::INT: {
        enterOuterAlt(_localctx, 2);
        setState(269);
        number();
        break;
      }

      case APPL_Parse::KW_TRUE:
      case APPL_Parse::KW_FALSE: {
        enterOuterAlt(_localctx, 3);
        setState(270);
        booln();
        break;
      }

      case APPL_Parse::ID: {
        enterOuterAlt(_localctx, 4);
        setState(271);
        match(APPL_Parse::ID);
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

APPL_Parse::Fun_callContext* APPL_Parse::fun_call() {
  Fun_callContext *_localctx = _tracker.createInstance<Fun_callContext>(_ctx, getState());
  enterRule(_localctx, 50, APPL_Parse::RuleFun_call);
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
    setState(274);
    match(APPL_Parse::ID);
    setState(275);
    match(APPL_Parse::LPAREN);
    setState(277);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 504719827009536038) != 0)) {
      setState(276);
      arg_list();
    }
    setState(279);
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

APPL_Parse::Arg_listContext* APPL_Parse::arg_list() {
  Arg_listContext *_localctx = _tracker.createInstance<Arg_listContext>(_ctx, getState());
  enterRule(_localctx, 52, APPL_Parse::RuleArg_list);
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
    setState(281);
    expr();
    setState(286);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == APPL_Parse::COMMA) {
      setState(282);
      match(APPL_Parse::COMMA);
      setState(283);
      expr();
      setState(288);
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

APPL_Parse::NumberContext* APPL_Parse::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 54, APPL_Parse::RuleNumber);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(291);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case APPL_Parse::FLT:
      case APPL_Parse::INT: {
        enterOuterAlt(_localctx, 1);
        setState(289);
        pos_num();
        break;
      }

      case APPL_Parse::SUB: {
        enterOuterAlt(_localctx, 2);
        setState(290);
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

APPL_Parse::Pos_numContext* APPL_Parse::pos_num() {
  Pos_numContext *_localctx = _tracker.createInstance<Pos_numContext>(_ctx, getState());
  enterRule(_localctx, 56, APPL_Parse::RulePos_num);
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
    setState(293);
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

APPL_Parse::Neg_numContext* APPL_Parse::neg_num() {
  Neg_numContext *_localctx = _tracker.createInstance<Neg_numContext>(_ctx, getState());
  enterRule(_localctx, 58, APPL_Parse::RuleNeg_num);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(295);
    match(APPL_Parse::SUB);
    setState(296);
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

APPL_Parse::BoolnContext* APPL_Parse::booln() {
  BoolnContext *_localctx = _tracker.createInstance<BoolnContext>(_ctx, getState());
  enterRule(_localctx, 60, APPL_Parse::RuleBooln);
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
    setState(298);
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

#pragma GCC visibility pop

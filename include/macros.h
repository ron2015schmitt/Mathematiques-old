#ifndef MATHQ__MACROS
#define MATHQ__MACROS



#define disp_strm(stream, ...) display::Display::mydispcr(stream, __VA_ARGS__, #__VA_ARGS__)
#define tdisp_strm(stream, ...) display::Display::tmydispcr(stream, __VA_ARGS__, #__VA_ARGS__)
#define trdisp_strm(stream, ...) display::Display::trmydispcr(stream, __VA_ARGS__, #__VA_ARGS__)
#define cr_strm(stream) display::Display::issuecr(stream)

#define dispval(...) display::dispval_strm(mout, __VA_ARGS__)
#define disp(...) display::Display::mydispcr(mout, __VA_ARGS__, #__VA_ARGS__)
#define tdisp(...) display::Display::tmydispcr(mout, __VA_ARGS__, #__VA_ARGS__)
#define trdisp(...) display::Display::trmydispcr(mout, __VA_ARGS__, #__VA_ARGS__)
#define cr() display::Display::issuecr(mout)

// for how this works, refer to
// https://stackoverflow.com/questions/3046889/optional-parameters-with-c-macros
#define disp_0(stream) display::Display::issuecr(stream)
#define dispX(stream, A) display::Display::mydisp(stream, A, #A)
#define disp_1(stream, A) \
  dispX(stream, A, #A);   \
  cr_strm(stream)
#define disp_2(stream, A, B) \
  dispX(stream, A);          \
  dispX(stream, B);          \
  cr_strm(stream)
#define disp_3(stream, A, B, C) \
  dispX(stream, A);             \
  dispX(stream, B);             \
  dispX(stream, C);             \
  cr_strm(stream)
#define disp_4(stream, A, B, C, D) \
  dispX(stream, A);                \
  dispX(stream, B);                \
  dispX(stream, C);                \
  dispX(stream, D);                \
  cr_strm(stream)
#define disp_5(stream, A, B, C, D, E) \
  dispX(stream, A);                   \
  dispX(stream, B);                   \
  dispX(stream, C);                   \
  dispX(stream, D);                   \
  dispX(stream, E);                   \
  cr_strm(stream)
#define disp_6(stream, A, B, C, D, E, F) \
  dispX(stream, A);                      \
  dispX(stream, B);                      \
  dispX(stream, C);                      \
  dispX(stream, D);                      \
  dispX(stream, E);                      \
  dispX(stream, F);                      \
  cr_strm(stream)
#define disp_7(stream, A, B, C, D, E, F, G) \
  dispX(stream, A);                         \
  dispX(stream, B);                         \
  dispX(stream, C);                         \
  dispX(stream, D);                         \
  dispX(stream, E);                         \
  dispX(stream, F);                         \
  dispX(stream, G);                         \
  cr_strm(stream)
#define disp_8(stream, A, B, C, D, E, F, G, H) \
  dispX(stream, A);                            \
  dispX(stream, B);                            \
  dispX(stream, C);                            \
  dispX(stream, D);                            \
  dispX(stream, E);                            \
  dispX(stream, F);                            \
  dispX(stream, G);                            \
  dispX(stream, H);                            \
  cr_strm(stream)
#define disp_9(stream, A, B, C, D, E, F, G, H, I) \
  dispX(stream, A);                               \
  dispX(stream, B);                               \
  dispX(stream, C);                               \
  dispX(stream, D);                               \
  dispX(stream, E);                               \
  dispX(stream, F);                               \
  dispX(stream, G);                               \
  dispX(stream, H);                               \
  dispX(stream, I);                               \
  cr_strm(stream)
#define disp_10(stream, A, B, C, D, E, F, G, H, I, J) \
  dispX(stream, A);                                   \
  dispX(stream, B);                                   \
  dispX(stream, C);                                   \
  dispX(stream, D);                                   \
  dispX(stream, E);                                   \
  dispX(stream, F);                                   \
  dispX(stream, G);                                   \
  dispX(stream, H);                                   \
  dispX(stream, I);                                   \
  dispX(stream, J);                                   \
  cr_strm(stream)

// The interim macro that simply strips the excess and ends up with the required macro
#define mdisp_X(x, A, B, C, D, E, F, G, H, I, J, FUNC, ...) FUNC;

// The macro that the programmer uses
#define mdisp(...) mdisp_X(, ##__VA_ARGS__, disp_10(mout, __VA_ARGS__), disp_9(mout, __VA_ARGS__), disp_8(mout, __VA_ARGS__), disp_7(mout, __VA_ARGS__), disp_6(mout, __VA_ARGS__), disp_5(mout, __VA_ARGS__), disp_4(mout, __VA_ARGS__), disp_3(mout, __VA_ARGS__), disp_2(mout, __VA_ARGS__), disp_1(mout, __VA_ARGS__), disp_0(mout))

#define mdisp_strm(stream, ...) mdisp_X(, ##__VA_ARGS__, disp_10(stream, __VA_ARGS__), disp_9(stream, __VA_ARGS__), disp_8(stream, __VA_ARGS__), disp_7(stream, __VA_ARGS__), disp_6(stream, __VA_ARGS__), disp_5(stream, __VA_ARGS__), disp_4(stream, __VA_ARGS__), disp_3(stream, __VA_ARGS__), disp_2(stream, __VA_ARGS__), disp_1(stream, __VA_ARGS__), disp_0(stream))

#if MATHQ_DEBUG >= 1
#define mdisp1(...) mdisp(__VA_ARGS__)
#define disp1(...) disp(__VA_ARGS__)
#define tdisp1(...) tdisp(__VA_ARGS__)
#else
#define mdisp1(...) \
  {}
#define disp1(...) \
  {}
#define tdisp1(...) \
  {}
#endif

#if MATHQ_DEBUG >= 2
#define mdisp2(...) mdisp(__VA_ARGS__)
#define disp2(...) disp(__VA_ARGS__)
#define tdisp2(...) tdisp(__VA_ARGS__)
#else
#define mdisp2(...) \
  {}
#define disp2(...) \
  {}
#define tdisp2(...) \
  {}
#endif

#if MATHQ_DEBUG >= 3
#define mdisp3(...) mdisp(__VA_ARGS__)
#define disp3(...) disp(__VA_ARGS__)
#define tdisp3(...) tdisp(__VA_ARGS__)
#else
#define mdisp3(...) \
  {}
#define disp3(...) \
  {}
#define tdisp3(...) \
  {}
#endif


#endif //file


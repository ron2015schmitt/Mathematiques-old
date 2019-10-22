# Refactor FormatData

* static if to print typeid(a).name() if .classname() does not exist, or just register classes that have classname() method
* use instances instead of class variables and use `constexpr` as needed
* collect all formats into one class
   * use a specific instance for disp/mout format
   * use a different specific instance for file i/o
* Define formats (via ENUM) for:
   * default-condensed
   * default-code
   * matlab
   * mathematica
   * csv,tsv,wsv 

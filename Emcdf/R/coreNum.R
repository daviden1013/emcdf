#' @title CPU core number
#' @description This function reports the total core number in CPU on the machine.
#'
#' @author En-shuo Hsu
#' @details
#' This function is a wrapper for the C++ function std::thread::hardware_concurrency();
#' If core number is not detected, 0 will be returned. See "See Also" for details.
#'
#' @export
#' @examples
#'
#' num = coreNum()
#'
#' @return
#' an integer indicating the total number of cores in CPU.
#'
#' @seealso
#' http://www.cplusplus.com/reference/thread/thread/hardware_concurrency/
coreNum = function(){
  return (getCoreNum())
}


import logging


logger = logging.getLogger(__name__)

def funcA(message):
    logger = logging.getLogger()
    logger.info("at funcA \"%s\"", message)
    logger.warn("at funcA \"%s\"", message)
    logger.error("at funcA \"%s\"", message)
    
    
def fail():
    logger.warn("warn")
    logger.exception("this is it")







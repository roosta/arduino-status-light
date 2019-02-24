(ns status-light
  (:require [serial.core :as serial]
            [serial.util :as util]))

(def port (serial/open "/dev/ttyUSB0"))

(defn -main [& args]

  )

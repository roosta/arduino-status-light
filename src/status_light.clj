(ns status-light
  (:require [serial-port :as serial]))

(def port (serial/open "/dev/ttyUSB0"))

(defn -main [& args]

  )

(ns status-light
  (:require [serial.core :as serial]
            [serial.util :as util]))

(defonce port (serial/open "/dev/ttyUSB0"))

(def fullscreen
  [31 31 31 31
   31 31 31 31
   31 31 31 31
   31 31 31 31])

(defn write-line
  []
  (serial/write port 0 0 31)
  (serial/write port 0 1 31)
  (serial/write port 0 2 31)
  (serial/write port 0 3 31)
  )

(defn -main [& args]

  )

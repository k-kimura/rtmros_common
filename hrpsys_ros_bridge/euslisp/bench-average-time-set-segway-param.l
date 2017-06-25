(defun main ()
  (let* ((i 0) (sum-time 0.0) ave-time)
    (do-until-key
     (let* ((sgp (* 10.0 (- (random 2.0) 1.0))) ;; random value from -10.0 to 10.0
            (this-time (bench2 (send *ri* :stabilizerservice_setsegwayparameter :i_param (instance hrpsys_ros_bridge::Openhrp_StabilizerService_sgParam :init :segway_param sgp))))
            ;;(this-time (bench2 (send (send *ri* :get-st-param) :segway_param)))
            ;;(this-time (bench2 (send *ri* :set-st-param :segway-param sgp)))
            )
       (incf i)
       (setq sum-time (+ sum-time this-time))
       (setq ave-time (/ sum-time i))
       (warn "Time (average) for set segway parameter: ~a [s]~%" ave-time)
       )
     )))

(warn ";; (main)~%")

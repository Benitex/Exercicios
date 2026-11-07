(defmacro ∘ (&rest functions)
  `(~> ,@(reverse functions)))

(defmacro ~> (&rest functions)
  (let ((value (gensym)))
    `(lambda (,value)
      ,(reduce (lambda (previous-expressions next-operator)
                  (if (listp next-operator)
                    `(funcall ,next-operator ,previous-expressions)
                    `(,next-operator ,previous-expressions)))
              functions
              :initial-value value))))

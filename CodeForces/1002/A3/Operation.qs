namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
            // your code here
            for(i in 0 .. Length(bits0)-1) {
                if(bits0[i] != bits1[1]){
                    H(qs[i]);
                    for(j in 0 .. Length(bits0)-1){
                        if(i != j){
                            if(bits0[j] != bits1[j]){
                                CNOT(qs[i], qs[j]);
                            } elif (bits0[j] == true){
                                X(qs[j]);
                            }
                        }
                    }
                    return ();
                }
            }
        }
    }
}

namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            // your code here
            mutable cnt = 0;
            for(i in 0 .. Length(qs)-1) {
                let m = M(qs[i]);
                if(m == One) {
                    set cnt = cnt+1;
                }
            }
            if(cnt == 1){
                return 1;
            }else{
                return 0;
            }
        }
    }
}
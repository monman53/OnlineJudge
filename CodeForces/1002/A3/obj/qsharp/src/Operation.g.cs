#pragma warning disable 1591
using System;
using Microsoft.Quantum.Primitive;
using Microsoft.Quantum.Simulation.Core;
using Microsoft.Quantum.MetaData.Attributes;

[assembly: OperationDeclaration("Solution", "Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()", new string[] { }, "/home/monman/online_judge/CodeForces/1002/A3/Operation.qs", 175L, 6L, 5L)]
#line hidden
namespace Solution
{
    public class Solve : Operation<(QArray<Qubit>,QArray<Boolean>,QArray<Boolean>), QVoid>, ICallable
    {
        public Solve(IOperationFactory m) : base(m)
        {
        }

        public class In : QTuple<(QArray<Qubit>,QArray<Boolean>,QArray<Boolean>)>, IApplyData
        {
            public In((QArray<Qubit>,QArray<Boolean>,QArray<Boolean>) data) : base(data)
            {
            }

            System.Collections.Generic.IEnumerable<Qubit> IApplyData.Qubits => ((IApplyData)Data.Item1)?.Qubits;
        }

        String ICallable.Name => "Solve";
        String ICallable.FullName => "Solution.Solve";
        protected IUnitary<(Qubit,Qubit)> MicrosoftQuantumPrimitiveCNOT
        {
            get;
            set;
        }

        protected IUnitary<Qubit> MicrosoftQuantumPrimitiveH
        {
            get;
            set;
        }

        protected IUnitary<Qubit> MicrosoftQuantumPrimitiveX
        {
            get;
            set;
        }

        public override Func<(QArray<Qubit>,QArray<Boolean>,QArray<Boolean>), QVoid> Body => (__in) =>
        {
            var (qs,bits0,bits1) = __in;
            // your code here
#line 10 "/home/monman/online_judge/CodeForces/1002/A3/Operation.qs"
            foreach (var i in new Range(0L, (bits0.Count - 1L)))
            {
#line 11 "/home/monman/online_judge/CodeForces/1002/A3/Operation.qs"
                if ((bits0[i] != bits1[1L]))
                {
#line 12 "/home/monman/online_judge/CodeForces/1002/A3/Operation.qs"
                    MicrosoftQuantumPrimitiveH.Apply(qs[i]);
#line 13 "/home/monman/online_judge/CodeForces/1002/A3/Operation.qs"
                    foreach (var j in new Range(0L, (bits0.Count - 1L)))
                    {
#line 14 "/home/monman/online_judge/CodeForces/1002/A3/Operation.qs"
                        if ((i != j))
                        {
#line 15 "/home/monman/online_judge/CodeForces/1002/A3/Operation.qs"
                            if ((bits0[j] != bits1[j]))
                            {
#line 16 "/home/monman/online_judge/CodeForces/1002/A3/Operation.qs"
                                MicrosoftQuantumPrimitiveCNOT.Apply((qs[i], qs[j]));
                            }
                            else if ((bits0[j] == true))
                            {
#line 18 "/home/monman/online_judge/CodeForces/1002/A3/Operation.qs"
                                MicrosoftQuantumPrimitiveX.Apply(qs[j]);
                            }
                        }
                    }

#line 22 "/home/monman/online_judge/CodeForces/1002/A3/Operation.qs"
                    return QVoid.Instance;
                }
            }

#line hidden
            return QVoid.Instance;
        }

        ;
        public override void Init()
        {
            this.MicrosoftQuantumPrimitiveCNOT = this.Factory.Get<IUnitary<(Qubit,Qubit)>>(typeof(Microsoft.Quantum.Primitive.CNOT));
            this.MicrosoftQuantumPrimitiveH = this.Factory.Get<IUnitary<Qubit>>(typeof(Microsoft.Quantum.Primitive.H));
            this.MicrosoftQuantumPrimitiveX = this.Factory.Get<IUnitary<Qubit>>(typeof(Microsoft.Quantum.Primitive.X));
        }

        public override IApplyData __dataIn((QArray<Qubit>,QArray<Boolean>,QArray<Boolean>) data) => new In(data);
        public override IApplyData __dataOut(QVoid data) => data;
        public static System.Threading.Tasks.Task<QVoid> Run(IOperationFactory __m__, QArray<Qubit> qs, QArray<Boolean> bits0, QArray<Boolean> bits1)
        {
            return __m__.Run<Solve, (QArray<Qubit>,QArray<Boolean>,QArray<Boolean>), QVoid>((qs, bits0, bits1));
        }
    }
}
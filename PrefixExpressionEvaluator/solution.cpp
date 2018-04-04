// Solution: Use a stack to get one element at a time (numbers could be multiple characters so
// assume that it's whitespace separated. When you come upon an operation, push it onto the stack.
// When you come upon a first number, push it onto the stack. When you come upon a second number,
// pop the top number off and pop the operation off, and perform the operation on the second number
// and the popped off (first) number.
double Evaluate(vector<string> &input) {
    vector<double> result;

    for(int i = input.size() - 1;i >= 0; i--)
    {
        if(!IsOperator(input[i]))
        {
            result.push_back(stoi(input[i]));
        }
        else
        {
            Assert(result.size() >= 2);

            double op1 = result.back();
            result.pop_back();

            double op2 = result.back();
            result.pop_back();

            double answer = PerformOperation(op1, op2, input[i]);
            result.push_back(answer);
        }
    }

    Assert(result.size() == 1);
    return result.back();
}

double PerformOperation(double op1, double op2, string oper) {
    switch(op)
    {
        op1 oper op2

        case "/"
          op == 0
            throw divideByzero
    }
}

bool IsOperator(string op) {
    return (op == "+" || op == "-" || op == "*" || op == "/");
}

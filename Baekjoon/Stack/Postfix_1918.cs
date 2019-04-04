using System;
using System.Collections.Generic;

/*
    Postfix 규칙
    1. 피연산자의 경우 출력
    2. ')'가 나오면 '('를 만날때까지 pop 및 출력
    3. 사칙연산자의 경우 top 우선순위가 낮은 경우, push한다
    4. 사칙연산자의 경우 top 우선순위가 자신보다 크거나 같은동안 top 출력 & pop을 하고, push한다
    5. stack이 빈 경우, 연산자는 push한다
    6. 연산자가 '('이거나 top이 '('인 경우, push한다
*/

namespace Postfix
{
    class Program
    {
        static void Main(string[] args)
        {
            var str = Console.ReadLine();

            Stack<char> stack = new Stack<char>();

            foreach (char ch in str)
            {
                // 피연산자
                if (ch >= 'A' && ch <= 'Z')
                {
                    Console.Write(ch);
                }
                // 연산자
                else
                {
                    // stack이 빈 경우 push
                    if (stack.Count == 0)
                    {
                        stack.Push(ch);
                    }
                    else
                    {
                        char top = stack.Peek();

                        // ch가 )인 경우 (까지 출력 및 pop
                        if (ch == ')')
                        {
                            while (stack.Peek() != '(')
                            {
                                Console.Write(stack.Peek());
                                stack.Pop();
                            }
                            stack.Pop();    // '(' 제거

                        }
                        // ch가 (인 경우 push
                        // top이 (인 경우 push
                        // top 우선순위가 낮은경우 push
                        else if (ch == '(' || top =='(' ||
                            ((top == '+' || top == '-') && (ch == '*' || ch == '/')))
                        {
                            stack.Push(ch);
                        }
                        // top 우선순위가 더 높거나 같은 경우 top 출력 및 pop후 push 반복
                        else
                        {
                            do
                            {
                                Console.Write(top);
                                stack.Pop();
                                if (stack.Count == 0) break;
                                top = stack.Peek();
                            } while (top != '(' && (ch == '+' || ch == '-' || ((ch == '*' || ch == '/') && (top == '*' || top == '/'))));

                            stack.Push(ch);
                        }
                    }
                }
            }

            while (stack.Count > 0)
            {
                if (stack.Peek() == '(' || stack.Peek() == ')')
                    stack.Pop();
                else
                    Console.Write(stack.Pop());
            }
        }
    }
}

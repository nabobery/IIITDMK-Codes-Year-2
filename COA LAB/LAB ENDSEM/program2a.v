module fulladder(a,b,cin,s,cout);
    input a,b,cin;
    output s,cout;
    assign s = (a^b)^cin;
    assign cout = (a&b)|(b&cin)|(a&cin);
endmodule

module fulladder_tb;
    wire t_s,t_cout;
    reg t_a,t_b, t_c;
    fulladder test(.a(t_a),.b(t_b),.cin(t_c),.s(t_s), .cout(t_cout));
    initial begin
    $monitor(t_a, t_b,t_c, " ", t_s, t_cout);
    t_a=1'b0;
    t_b=1'b0;
    t_c =1'b0;
    #5
    t_a=1'b0;
    t_b=1'b0;
    t_c =1'b1;
    #5
    t_a=1'b0;
    t_b=1'b1;
    t_c =1'b0;
    #5
    t_a=1'b0;
    t_b=1'b1;
    t_c =1'b1;
    #5
    t_a=1'b1;
    t_b=1'b0;
    t_c =1'b0;
    #5
    t_a=1'b1;
    t_b=1'b0;
    t_c =1'b1;
    #5
    t_a=1'b1;
    t_b=1'b1;
    t_c =1'b0;
    #5
    t_a=1'b1;
    t_b=1'b1;
    t_c =1'b1;
    end
endmodule

module notgate(x,y);
    input x;
    output y;
    assign y = ~x;
endmodule

module notgate_tb;
    wire t_y;
    reg t_x;
    notgate test(.x(t_x),.y(t_y));
    initial begin
    $monitor(t_x, " ", t_y);
    t_x=1'b0;
    #5
    t_x = 1'b1;
    end
endmodule

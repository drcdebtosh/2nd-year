Port (A: in STD_LOGIC_VECTOR (1 downto 0):
      B: in STD_LOGIC_VECTOR (1 downto 0);
      S: in STD_LOGIC_VECTOR (1 downto 0);
      Y: in STD_LOGIC_VECOTOR (1 downto 0));
    
BEGIN
    PROCESS (A,B,S)
    BEGIN
    CASE S IS
    WHEN "00"=>Y<=A+B;
    WHEN "00"=>Y<=A+(NOT B)+1;
    WHEN "00"=>Y<=A AND B;
    WHEN OTHERS =>Y<=A OR B;
    END CASE;
    END PROCESS;
END Behavioral;
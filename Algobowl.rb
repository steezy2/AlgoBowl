def create_input(n)
  outputarr = []
  max = 100
  value = 2
  for i in 1..n do
    value = rand(value..max+value)
    line = "#{value}"
    outputarr << line
  end
  outputarr
end


n = 8

inputarr = create_input(8)

inputarr.each { |x| puts x }
firstline = n.to_s+"\n"
File.open("Algoinput.txt", "w") { |f| f.write firstline
  f.write inputarr.join(" ") }

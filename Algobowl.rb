def create_input(n)
  outputarr = []
  max = rand(1000)
  value = 2
  for i in 1..n do
    max = rand(7000000)
    value = rand(value..max+value)
    line = "#{value}"
    outputarr << line
  end
  outputarr
end


n = 500

inputarr = create_input(n)

inputarr.each { |x| puts x }
firstline = n.to_s+"\n"
File.open("Algoinput.txt", "w") { |f| f.write firstline
  f.write inputarr.join(" ") }

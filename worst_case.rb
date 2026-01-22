# worst_case.rb
max_ops = 0
worst_arg = ""

puts "🔍 Hunting for the worst case scenario (100 numbers)..."

500.times do |i|
  # توليد 100 رقم عشوائي
  arg = (1..5).to_a.shuffle.join(" ")
  
  # تشغيل البرنامج وحساب الخطوات
  output = `./push_swap #{arg}`
  ops = output.split("\n").size
  
  # إذا وجدنا عدداً أكبر من السابق، نحفظه
  if ops > max_ops
    max_ops = ops
    worst_arg = arg
    puts "Found new worst case: #{max_ops} instructions (Iter: #{i})"
  end
end

puts "\n---------------------------------------------------"
puts "😈 WORST CASE FOUND (#{max_ops} ops):"
puts worst_arg
puts "---------------------------------------------------"
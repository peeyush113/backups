package cetus.exec;

import java.util.*;

public class CommandLineOptionSet
{
  private class OptionRecord
  {
    public String value;
    public String arg;
    public String usage;

    public OptionRecord(String usage)
    {
      this.value = null;
      this.arg = null;
      this.usage = new String(usage);
    }

    public OptionRecord(String arg, String usage)
    {
      this.value = null;
      this.arg = new String(arg);
      this.usage = new String(usage);
    }
  }

  private TreeMap<String, OptionRecord> name_to_record;

  public CommandLineOptionSet()
  {
    name_to_record = new TreeMap<String, OptionRecord>();
  }

  public void add(String name, String usage)
  {
    name_to_record.put(name, new OptionRecord(usage));
  }

  public void add(String name, String arg, String usage)
  {
    name_to_record.put(name, new OptionRecord(arg, usage));
  }

  public boolean contains(String name)
  {
    return name_to_record.containsKey(name);
  }

  public String getUsage()
  {
    String usage = new String();

    Iterator<Map.Entry<String, OptionRecord>> iter
      = name_to_record.entrySet().iterator();

    while (iter.hasNext())
    {
      Map.Entry<String, OptionRecord> pair = iter.next();

      usage += "  -"; 
      usage += pair.getKey();

      OptionRecord record = pair.getValue();

      if (record.arg != null)
      {
        usage += "=";
        usage += record.arg;
      }

      usage += "\n    ";
      usage += record.usage;
      usage += "\n";
    }

    return usage;
  }

  public String getValue(String name)
  {
    OptionRecord record = name_to_record.get(name);

    if (record == null)
      return new String();
    else
      return record.value;
  }

  public void setValue(String name, String value)
  {
    OptionRecord record = name_to_record.get(name);

    if (record != null)
      record.value = value;
  }
}

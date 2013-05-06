using UnityEngine;
public class AGNoise : MonoBehaviour
{
  static int init = 307;
  private int ag_seed = (init *= 1319);

  public void OnAudioFilterRead(float[] data, int channels)
  {
    int val = ag_seed;
    for (int i = 0; i < data.Length; i++)
    {
      data[i] = ((float)((val & 0x7fffffff) - 0x40000000)) *
                    (float)(1.0 / 0x40000000);
      val = val * 435898247 + 382842987;
    }
    ag_seed = val;
  }

}
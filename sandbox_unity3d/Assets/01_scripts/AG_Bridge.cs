using UnityEngine;
using System.Runtime.InteropServices;

public class AG_Bridge : MonoBehaviour
{	
  // This preliminary version is only able to instantiates one single instance
  [DllImport ("audio_bridge")]
  private static extern void init();

  [DllImport ("audio_bridge")]
  private static extern void set_parameter(float value);

  [DllImport ("audio_bridge")]
  private static extern void process(int block_size);

  [DllImport ("audio_bridge")]
  private static extern int get_value(int sample_count);
	
  public float gain;
  public float frequency;
  
  // next version prototype
  // int create_instance();  // return an handle
  // public set_float_parameters(int handle, int parameter_name, float parameter_value);
  //
  // void destroy_instance(int handle);

  public void Awake() {
  //Here we should manage the init of the dll
    init();
  }
  
  public void OnAudioFilterRead(float[] data, int channels) {
	// We update all paramters here
	set_parameter(frequency);
	// Then we generate an audio block	
	process(data.Length);
	// an we fill the buffer with the data.
    for (int i = 0; i < data.Length; i++)
    {
      data[i] = get_value(i)*gain;
    }
  }
}
<template>
  <div class="w-full relative">
    <div
      class="result md:flex md:justify-between md:items-center max-w-6xl mx-auto rounded-md shadow-sm bg-white py-4"
    >
      <span
        class="block mx-2 mb-2 md:mb-0 sm:mx-4 lg:mx-6 font-light max-w-md truncate"
      >
        {{ result.link }}
      </span>
      <span class="block mx-2 sm:mx-4 lg:mx-6 text-indigo-600">
        <a :href="shortLink">{{ shortLink }}</a>
      </span>
    </div>
    <div class="reset absolute w-full text-center text-sm">
      <span
        class="tracking-wide text-gray-100 cursor-pointer border-b border-gray-100 border-dotted"
        @click="$emit('reset')"
      >
        Shorten another link
      </span>
    </div>
  </div>
</template>

<script lang="ts">
import { defineComponent, computed, toRefs, toRef, PropType } from "vue";

export default defineComponent({
  name: "LinkResultSuccess",
  props: {
    result: Object as PropType<{ link: string; shortLink: string }>
  },
  setup(props) {
    const shortLink = computed(
      () => `https://kuy.sh${props.result!.shortLink}`
    );

    return { shortLink };
  }
});
</script>

<style scoped>
.result {
  min-height: 3.5rem;
}

.reset {
  bottom: -2rem;
}
</style>
